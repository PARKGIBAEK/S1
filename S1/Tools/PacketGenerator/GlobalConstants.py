# -*- coding: utf-8 -*-

PROTO_DIR = "./proto_files"  # .proto 파일이 있는 경로
TEMP_OUTPUT_DIR = "./generated"  # 생성된 서버용 protobuf 코드를 저장할 임시 경로
PROTOC_COMMAND = "protoc.exe"  # protobuf 컴파일러 명령어

SERVER_INCLUDE_DIR = "../../GameServer/Network/Protocol"  # 생성된 코드 파일을 이동할 Server쪽 경로
DUMMY_CLIENT_INCLUDE_DIR = "../../DummyClient/Network/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로
UNREAL_CLIENT_INCLUDE_DIR = "../../../../C1/Source/C1/Network/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로

SERVER_SOURCE_DIR = "../../GameServer/Network/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로
DUMMY_CLIENT_SOURCE_DIR = "../../DummyClient/Network/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로
UNREAL_CLIENT_SOURCE_DIR = "../../../../C1/Source/C1/Network/Protocol"  # 생성된 코드 파일을 이동할 Client쪽 경로

SERVER_HANDLER_DIR = "../../GameServer/Network"  # 생성된 코드 파일을 이동할 Client쪽 경로
DUMMY_CLIENT_HANDLER_DIR = "../../DummyClient/Network"  # 생성된 코드 파일을 이동할 Client쪽 경로
UNREAL_CLIENT_HANDLER_DIR = "../../../../C1/Source/C1/Network"  # 생성된 코드 파일을 이동할 Client쪽 경로

REQ_MESSAGE_SUFFIX = '_REQ'
ACK_MESSAGE_SUFFIX = '_ACK'

SERVER_HANDLER_OUTPUT_NAME = 'PacketHandler.h'
DUMMY_CLIENT_HANDLER_OUTPUT_NAME = 'PacketHandler.h'
UNREAL_CLIENT_HANDLER_OUTPUT_NAME = 'PacketHandler.h'

SERVER_NAMESPACE = 'GameServer'
DUMMY_CLIENT_NAMESPACE = 'DummyClient'
UNREAL_CLIENT_NAMESPACE = 'UnrealClient'
