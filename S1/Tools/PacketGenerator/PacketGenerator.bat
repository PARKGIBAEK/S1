
:: 현재 디렉토리를 스택에 저장하고, 배치 파일이 위치한 디렉토리로 이동

pushd %~dp0


:: protoc 컴파일러 옵션 설명

:: -I : '*.proto' 파일이 있는 경로
:: --cpp_out : C++ 소스 파일을 생성할 경로
:: '*.proto' 파일명


protoc.exe -I=./protofiles --cpp_out=./generated Enum.proto
protoc.exe -I=./protofiles --cpp_out=./generated Struct.proto
protoc.exe -I=./protofiles --cpp_out=./generated Protocol.proto


PacketGenerator.exe --path=./protofiles/Protocol.proto --output=ClientPacketHandler --req=_REQ --ack=_ACK --namespace=GameServer
PacketGenerator.exe --path=./protofiles/Protocol.proto --output=ServerPacketHandler --req=_REQ --ack=_ACK --namespace=DummyClient

IF ERRORLEVEL 1 PAUSE

XCOPY /Y generated\Enum.pb.h "../../GameServer/Protocol"
XCOPY /Y generated\Enum.pb.cc "../../GameServer/Protocol"
XCOPY /Y generated\Struct.pb.h "../../GameServer/Protocol"
XCOPY /Y generated\Struct.pb.cc "../../GameServer/Protocol"
XCOPY /Y generated\Protocol.pb.h "../../GameServer/Protocol"
XCOPY /Y generated\Protocol.pb.cc "../../GameServer/Protocol"
XCOPY /Y generated\ClientPacketHandler.h "../../GameServer/Protocol"

XCOPY /Y generated\Enum.pb.h "../../DummyClient/Protocol"
XCOPY /Y generated\Enum.pb.cc "../../DummyClient/Protocol"
XCOPY /Y generated\Struct.pb.h "../../DummyClient/Protocol"
XCOPY /Y generated\Struct.pb.cc "../../DummyClient/Protocol"
XCOPY /Y generated\Protocol.pb.h "../../DummyClient/Protocol"
XCOPY /Y generated\Protocol.pb.cc "../../DummyClient/Protocol"
XCOPY /Y generated\ServerPacketHandler.h "../../DummyClient/Protocol"

:: 따음표가 없으면 경로 구분자는 /가 아니라 \로 해야한다
DEL /Q /F generated\*.pb.h
DEL /Q /F generated\*.pb.cc
DEL /Q /F generated\*.h

PAUSE