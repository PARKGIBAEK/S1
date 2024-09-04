# -*- coding: utf-8 -*-
import argparse
import glob
import re
import shutil
import subprocess

import jinja2
import ProtoParser
import os

from GlobalConstants import *


# 경로(directory)의 존재 여부 확인하고 없으면 생성 함
def ensure_dir(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)


# 대상 파일이 이미 존재하면 삭제 후 이동
def move_and_overwrite(src, dst):
    # dst의 경로 부분만 추출
    dst_dir = os.path.dirname(dst)
    # 경로가 존재하지 않으면 생성
    ensure_dir(dst_dir)
    # 대상 파일이 이미 존재하면 삭제
    if os.path.exists(dst):
        os.remove(dst)
    # 파일 복사(복사 후 원본 파일 유지)
    shutil.copy(src, dst)


def run_command(command):
    # 외부 명령어(command) 실행 후 결과 출력&반환
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


def generate_packet_handler(proto_parser: ProtoParser, output_name: str, output_directory: str,
                            handler_template_name: str):
    # 템플릿 로더 설정(템플릿 경로를 Templates로 설정)
    file_loader = jinja2.FileSystemLoader('PacketHandlerTemplates')
    env = jinja2.Environment(loader=file_loader)  # Jinja2 환경 설정

    template = env.get_template(handler_template_name)  # PacketHandler.h 템플릿 로드
    class_name = output_name[:-2]
    output = template.render(parser=proto_parser, class_name=class_name)  # 템플릿 렌더링

    output_path = os.path.join(output_directory, output_name).replace('\\', '/')

    with open(output_path, 'w+', encoding="utf-8") as f:
        f.write(output)
    print(f"Generated \'{output_name}\'")
    print(f"{output}")


def compile_proto_messages_and_copy_results(args: argparse.Namespace):
    for proto_file in glob.glob(os.path.join(args.path, '*.proto')):
        proto_filename = os.path.basename(proto_file)  # proto 파일명 가져오기
        proto_filename_without_extension = os.path.splitext(proto_filename)[0]  # 파일명에서 확장자 제거

        # 컴파일 명령어 예시) protoc.exe -I=./proto_files --cpp_out=./generated Enum.proto
        run_command(f"{PROTOC_COMMAND} -I={PROTO_DIR} --cpp_out={TEMP_OUTPUT_DIR} {proto_file}")

        # 복사 목적지(Server) 경로 설정
        generated_header_filepath = os.path.join(TEMP_OUTPUT_DIR, f"{proto_filename_without_extension}.pb.h")
        generated_source_filepath = os.path.join(TEMP_OUTPUT_DIR, f"{proto_filename_without_extension}.pb.cc")
        # 복사 목적지(서버) 경로
        dest_header_filepath_for_server = os.path.join(SERVER_INCLUDE_DIR, f"{proto_filename_without_extension}.pb.h")
        dest_source_filepath_for_unreal = os.path.join(SERVER_SOURCE_DIR, f"{proto_filename_without_extension}.pb.cc")
        # 복사 목적지(Server)로 복사
        move_and_overwrite(generated_header_filepath, dest_header_filepath_for_server)  # .cc 또는 cpp 파일 이동
        move_and_overwrite(generated_source_filepath, dest_source_filepath_for_unreal)  # .cc 또는 cpp 파일 이동

        # 복사 목적지(DummyClient) 경로 설정
        dest_header_filepath_for_client = os.path.join(DUMMY_CLIENT_SOURCE_DIR,
                                                       f"{proto_filename_without_extension}.pb.h")
        dest_source_filepath_for_client = os.path.join(DUMMY_CLIENT_SOURCE_DIR,
                                                       f"{proto_filename_without_extension}.pb.cc")
        # 복사 목적지(DummyClient)로 복사
        move_and_overwrite(generated_header_filepath, dest_header_filepath_for_client)  # .cc 또는 cpp 파일 이동
        move_and_overwrite(generated_source_filepath, dest_source_filepath_for_client)  # .cc 또는 cpp 파일 이동

        # 중요 사항
        # protobuf message 컴파일 시 Unreal Engine용 코드는
        # '*.proto'파일에 Arena Allocation를 비활성화시키는 옵션(cc_enable_arenas = false)을 추가하여 컴파일 해야 한다
        # Unreal Engine 용 코드 생성하기(Arena Allocation 비활성화 옵션 추가하기)
        with open(PROTO_DIR + "/" + proto_filename, 'r') as f:
            proto_file_content = f.read()  # '*.proto' 파일 원본 내용 가져오기

        # '*.proto' 파일 원본 내용에 Arena Allocation를 비활성화시키는 옵션(cc_enable_arenas = false)을 추가하기
        # (syntax 선언 다음 줄에 option cc_enable_arenas = false; 코드 추가한다)
        modified_proto_file_content = re.sub(
            r'(syntax\s*=\s*"proto3"\s*;)',
            r'\1\n\noption cc_enable_arenas = false;\n',
            proto_file_content
        )

        # Unreal Engine용 임시 proto 파일 생성(옵션 코드 추가 됨)
        temp_proto_file_path = PROTO_DIR + "/" + proto_filename_without_extension + "_modified.proto"  # 임시 파일 명 지정
        with open(temp_proto_file_path, 'w') as f:
            f.write(modified_proto_file_content)

        # Unreal Engine용 packet 코드 컴파일
        # 예) protoc.exe -I=./proto_files --cpp_out=./generated Enum.proto
        run_command(f"{PROTOC_COMMAND} -I={PROTO_DIR} --cpp_out={TEMP_OUTPUT_DIR} {proto_file}")
        # Unreal Engine 용 임시 proto파일 삭제
        os.remove(temp_proto_file_path)

        # 복사 목적지(언리얼 클라) 경로
        dest_header_filepath_for_unreal = os.path.join(UNREAL_CLIENT_INCLUDE_DIR,
                                                       f"{proto_filename_without_extension}.pb.h")
        dest_source_filepath_for_unreal = os.path.join(UNREAL_CLIENT_SOURCE_DIR,
                                                       f"{proto_filename_without_extension}.pb.cc")
        # 언리얼 클라로 복사/이동
        move_and_overwrite(generated_header_filepath, dest_header_filepath_for_unreal)  # .cc 또는 cpp 파일 이동
        move_and_overwrite(generated_source_filepath, dest_source_filepath_for_unreal)  # .cc 또는 cpp 파일 이동


# protobuf 컴파일러로 ~.proto 파일을 컴파일한 결과물과
# 템플릿 엔진 jinja2로 Template 파일인 PacketHandler.h에 대한 렌더링 결과물을
# --output 경로에 생성한다
def main():
    # 1. CLI 인자를 받기 위한 argparse 초기화
    arg_parser = argparse.ArgumentParser(description='PacketGenerator')

    # TODO : 추후 경로 변경

    arg_parser.add_argument('--path', type=str, default=PROTO_DIR, help='\'*.proto\' file path')
    arg_parser.add_argument('--server_output', type=str, default=SERVER_HANDLER_OUTPUT_NAME,
                            help='output handler name including directory')
    arg_parser.add_argument('--dummy_output', type=str, default=DUMMY_CLIENT_HANDLER_OUTPUT_NAME,
                            help='output handler name including directory')
    arg_parser.add_argument('--client_output', type=str, default=UNREAL_CLIENT_HANDLER_OUTPUT_NAME,
                            help='output handler name including directory')
    arg_parser.add_argument('--req', type=str, default=REQ_MESSAGE_SUFFIX, help='Request packet suffix convention')
    arg_parser.add_argument('--ack', type=str, default=ACK_MESSAGE_SUFFIX, help='Acknowlege packet suffix convention')
    # arg_parser.add_argument('--namespace', type=str, default='#error', help='namespace')
    arg_parser.add_argument('--namespace_for_server', type=str, default=SERVER_NAMESPACE, help='namespace')
    arg_parser.add_argument('--namespace_for_client', type=str, default=DUMMY_CLIENT_NAMESPACE, help='namespace')
    args = arg_parser.parse_args()

    # 경로의 존재 여부 확인하고 없으면 생성 함
    ensure_dir(TEMP_OUTPUT_DIR)
    ensure_dir(SERVER_INCLUDE_DIR)
    ensure_dir(DUMMY_CLIENT_INCLUDE_DIR)

    # 2. protobuf message 컴파일
    compile_proto_messages_and_copy_results(args)

    # protobuf 컴파일러(protoc.exe)의 default 경로를 현재 프로그램의 실행 파일이 있는 경로로 지정
    exe_dir = os.path.dirname(os.path.abspath(__file__))

    # 3. PacketHandler생성에 필요한 정보를 얻기 위해 '*.proto'를 파싱하기
    proto_parser_server = ProtoParser.ProtoParser(1000, REQ_MESSAGE_SUFFIX, ACK_MESSAGE_SUFFIX, SERVER_NAMESPACE)
    proto_parser_dummy_client = ProtoParser.ProtoParser(1000, REQ_MESSAGE_SUFFIX, ACK_MESSAGE_SUFFIX,
                                                        DUMMY_CLIENT_NAMESPACE)
    proto_parser_unreal_client = ProtoParser.ProtoParser(1000, REQ_MESSAGE_SUFFIX, ACK_MESSAGE_SUFFIX,
                                                         UNREAL_CLIENT_NAMESPACE)

    # '*.proto'파일 다불러오기
    for proto_file in glob.glob(os.path.join(args.path, '*.proto')):
        # PacketGenerator실행
        proto_parser_server.parse_proto_messages(proto_file)
        proto_parser_dummy_client.parse_proto_messages(proto_file)
        proto_parser_unreal_client.parse_proto_messages(proto_file)

    # 4. PacketHandler 생성하기
    generate_packet_handler(proto_parser_server, args.server_output, SERVER_HANDLER_DIR, 'PacketHandler.h')
    generate_packet_handler(proto_parser_dummy_client, args.dummy_output, DUMMY_CLIENT_HANDLER_DIR, 'PacketHandler.h')
    generate_packet_handler(proto_parser_unreal_client, args.client_output, UNREAL_CLIENT_HANDLER_DIR,
                            'PacketHandler.h')

    # 4. 임시 경로 & 파일 정리
    shutil.rmtree(TEMP_OUTPUT_DIR, ignore_errors=True)

    return


if __name__ == '__main__':
    main()
