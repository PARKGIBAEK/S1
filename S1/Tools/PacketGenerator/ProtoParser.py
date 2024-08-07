class ProtoParser():

    def __init__(self, start_id, req_suffix, ack_suffix, namespace):
        self.start_id = start_id
        self.id = start_id
        self.req_suffix = req_suffix  # 요청 패킷 접미사
        self.ack_suffix = ack_suffix  # 응답 패킷 접미사
        self.namespace = namespace
        self.req_pkts = []  # 요청 패킷 목록
        self.ack_pkts = []  # 응답 패킷 목록
        self.total_pkts = []  # 모든 패킷 목록


    def parse_proto(self, path):
        with open(path, 'r') as proto_file:
            lines = proto_file.readlines()

        # ~.proto파일 내용을 한줄씩 전달
        for line in lines:
            if not line.startswith('message'):
                continue
            # 프로토콜 구조체 이름 파싱하기
            pkt_name = line.split()[1].upper()

            if pkt_name.endswith('{'):  # message명 뒤에 '{' 있으면 제거
                pkt_name = pkt_name[:-1]

            # recv_suffix인 _C인 경우와 send_suffix인 _S인 경우에 따라 처리
            if pkt_name.endswith(self.req_suffix):
                self.req_pkts.append(Packet(pkt_name, self.id))
            elif pkt_name.endswith(self.ack_suffix):
                self.ack_pkts.append(Packet(pkt_name, self.id))
            else:
                continue
            self.total_pkts.append(Packet(pkt_name, self.id))
            self.id += 1

        proto_file.close()


class Packet:
    def __init__(self, name, packet_id):
        self.name = name
        self.packet_id = packet_id
