# -*- coding: utf-8 -*-
import jinja2


class ProtoParser():

    def __init__(self, start_id: int, req_suffix: str, ack_suffix: str, namespace: str):
        self.start_id = start_id
        self.id = start_id
        self.req_suffix = req_suffix  # 요청 메시지 패킷 접미사
        self.ack_suffix = ack_suffix  # 응답 메시지 패킷 접미사
        self.namespace = namespace
        self.req_messages = []  # 요청 메시지 패킷 목록
        self.ack_messages = []  # 응답 메시지 패킷 목록
        self.total_messages = []  # 모든 메시지 패킷 목록

    def parse_proto_messages(self, path: str):
        with open(path, 'r') as proto_file:
            lines = proto_file.readlines()

        # ~.proto파일 내용을 한줄씩 전달
        for line in lines:
            if not line.startswith('message'):
                continue
            # 프로토콜 구조체 이름 파싱하기
            message_name = line.split()[1].upper()

            if message_name.endswith('{'):  # message명 뒤에 '{' 있으면 제거
                message_name = message_name[:-1]

            # recv_suffix인 _C인 경우와 send_suffix인 _S인 경우에 따라 처리
            if message_name.endswith(self.req_suffix):
                self.req_messages.append(ProtobufMessage(message_name, self.id))
            elif message_name.endswith(self.ack_suffix):
                self.ack_messages.append(ProtobufMessage(message_name, self.id))
            else:
                continue
            self.total_messages.append(ProtobufMessage(message_name, self.id))
            self.id += 1

        proto_file.close()



class ProtobufMessage:
    def __init__(self, name, message_id):
        self.name = name
        self.message_id = message_id
