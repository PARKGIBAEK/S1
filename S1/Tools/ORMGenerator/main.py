# coding=utf-8
# ORMGenerator/main.py
import argparse
import mysql
from orm_generator import OrmGenerator


def main():
    #  argparse모듈로 command line arguments를 파싱
    parser = argparse.ArgumentParser(description="Generate c++ ORM file")
    parser.add_argument("--host", default="localhost", help="host address(default = localhost)")
    parser.add_argument("--user", default="root", help="MySQL user name (default = root)")
    parser.add_argument("--password", default="tkdring", help="MySQL user password(default = tkdring)")
    parser.add_argument("--database", default="test", help="MySQL databse name(default = test)")
    parser.add_argument("--port", default=3308, help="default port(default = 3308)")
    parser.add_argument("--output", default="../../GameServer/DB/ORM",
                        help="output directory(default = ../../GameServer/DB/ORM)")

    try:
        args = parser.parse_args()

        host = args.host
        user = args.user
        password = args.password
        database = args.database
        port = args.port

        orm_gen = OrmGenerator(args.output, host, user, password, database, port)

        orm_gen.generate_orm_for_database()

    except mysql.connector.Error as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
