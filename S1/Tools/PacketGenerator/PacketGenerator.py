# -*- coding: utf-8 -*-
import argparse
import glob
import shutil
import subprocess

import jinja2
import ProtoParser
import os

PROTO_DIR = "./protofiles"  # .proto 파일이 있는 경로
TEMP_OUTPUT_DIR = "./generated"  # 생성된 protobuf 코드를 저장할 임시 경로
PROTOC_COMMAND = "protoc.exe"  # protobuf 컴파일러 명령어
SERVER_INCLUDE_DIR = "../../GameServer/Protocol"  # 생성된 코드 파일을 이동할 Server쪽 경로
CLIENT_INCLUDE_DIR = "../../DummyClient/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로
SERVER_SOURCE_DIR = "../../GameServer/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로
CLIENT_SOURCE_DIR = "../../DummyClient/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로
REQ_PACKET_SUFFIX = '_REQ'
ACK_PACKET_SUFFIX = '_ACK'
SERVER_HANDLER_OUTPUT_NAME = 'ServerPacketHandler.h'
CLIENT_HANDLER_OUTPUT_NAME = 'ClientPacketHandler.h'
SERVER_NAMESPACE = 'GameServer'
CLIENT_NAMESPACE = 'DummyClient'


def ensure_dir(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)


def move_and_overwrite(src, dst):
    # 대상 파일이 이미 존재하면 삭제 후 이동
    if os.path.exists(dst):
        os.remove(dst)
    shutil.copy(src, dst)


def run_command(command):
    # 외부 명령어 실행 및 결과 반환
    try:
        result = subprocess.run(command, check=True, shell=True, capture_output=True, text=True)
        print(f"Command executed: {command}")
        print("Standard Output:")
        print(result.stdout)
        if result.stderr:
            print("Standard Error:")
            print(result.stderr)
        return result
    except subprocess.CalledProcessError as e:
        print(f"Error executing command: {command}")
        print(f"Error message: {e}")
        print("Standard Output:")
        print(e.stdout)
        print("Standard Error:")
        print(e.stderr)
        exit(1)  # 오류 발생 시 프로그램 종료


def generate_packet_handler(proto_file_path, output_name, req_suffix, ack_suffix, namespace):
    parser = ProtoParser.ProtoParser(1000, req_suffix, ack_suffix, namespace)
    # ProtoParser로 프로토콜 구조체 이름 파싱하기
    parser.parse_proto(proto_file_path)

    # 템플릿 로더 설정(템플릿 경로를 Templates로 설정)
    file_loader = jinja2.FileSystemLoader('Templates')
    env = jinja2.Environment(loader=file_loader)  # Jinja2 환경 설정

    template = env.get_template('PacketHandler.h')  # PacketHandler.h 템플릿 로드
    output = template.render(parser=parser, output=output_name)  # 템플릿 렌더링

    with open(output_name, 'w+', encoding='utf-8') as f:
        f.write(output)
    print(f"Generated \'{output_name}\'")
    print(f"{output}")


# protobuf 컴파일러로 ~.proto 파일을 컴파일한 결과물과
# 템플릿 엔진 jinja2로 Template 파일인 PacketHandler.h에 대한 렌더링 결과물을
# --output 경로에 생성한다
def main():
    # CLI 인자 라이브러리 arg_parser 초기화
    arg_parser = argparse.ArgumentParser(description='PacketGenerator')
    # 사용 시 경로 변경

    # protobuf 컴파일러(protoc.exe)의 default 경로를 이 실행 프로그램이 있는 경로로 지정
    exe_dir = os.path.dirname(os.path.abspath(__file__))

    arg_parser.add_argument('--path', type=str, default=PROTO_DIR, help='\'*.proto\' file path')
    arg_parser.add_argument('--server_output', type=str, default=SERVER_HANDLER_OUTPUT_NAME,
                            help='output handler name including directory')
    arg_parser.add_argument('--client_output', type=str, default=CLIENT_HANDLER_OUTPUT_NAME,
                            help='output handler name including directory')
    arg_parser.add_argument('--req', type=str, default=REQ_PACKET_SUFFIX, help='Request packet suffix convention')
    arg_parser.add_argument('--ack', type=str, default=ACK_PACKET_SUFFIX, help='Acknowlege packet suffix convention')
    arg_parser.add_argument('--namespace', type=str, default='#error', help='namespace')
    args = arg_parser.parse_args()

    ensure_dir(TEMP_OUTPUT_DIR)
    ensure_dir(SERVER_INCLUDE_DIR)
    ensure_dir(CLIENT_INCLUDE_DIR)

    # '*.proto'파일 다불러오기
    for proto_file in glob.glob(os.path.join(PROTO_DIR, "*.proto")):
        filename = os.path.basename(proto_file)
        name_without_ext = os.path.splitext(filename)[0]

        # protofub 컴파일
        # ex) protoc.exe -I=./protofiles --cpp_out=./generated Enum.proto
        run_command(f"{PROTOC_COMMAND} -I={PROTO_DIR} --cpp_out={TEMP_OUTPUT_DIR} {proto_file}")

        # PacketGenerator실행
        generate_packet_handler(proto_file, args.server_output, args.req, args.ack, args.namespace)
        generate_packet_handler(proto_file, args.client_output, args.req, args.ack, args.namespace)

        # 생성된 파일 이동
        for generated_file in glob.glob(os.path.join(TEMP_OUTPUT_DIR, f"{name_without_ext}*")):
            filename_to_move = os.path.basename(generated_file)
            server_header_dir = os.path.join(SERVER_INCLUDE_DIR, filename_to_move).replace('\\', '/')
            client_header_dir = os.path.join(CLIENT_INCLUDE_DIR, filename_to_move).replace('\\', '/')
            server_source_dir = os.path.join(SERVER_SOURCE_DIR, filename_to_move).replace('\\', '/')
            client_source_dir = os.path.join(CLIENT_SOURCE_DIR, filename_to_move).replace('\\', '/')
            filepath_to_copy = generated_file.replace('\\', '/')
            if filepath_to_copy.endswith('.h'):
                move_and_overwrite(filepath_to_copy, server_header_dir)  # .h 파일 이동
                move_and_overwrite(filepath_to_copy, client_header_dir)  # .h 파일 이동
            elif filepath_to_copy.endswith('.cc') or generated_file.endswith('.cpp'):
                move_and_overwrite(filepath_to_copy, server_source_dir)  # .cc 또는 cpp 파일 이동
                move_and_overwrite(filepath_to_copy, client_source_dir)  # .cc 또는 cpp 파일 이동

    # 임시 디렉토리 정리
    shutil.rmtree(TEMP_OUTPUT_DIR, ignore_errors=True)

    return


if __name__ == '__main__':
    main()
