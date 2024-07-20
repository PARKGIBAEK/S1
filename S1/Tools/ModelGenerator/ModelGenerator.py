import os
import re
import argparse
import SqlParser

# ModelGenerator는 Model 코드에 attribute나 Nullable같은 옵션들을 명시한다
# 그러나 수많은 옵션들을 정확하게 명시하지 못하여
# 예외가 자주 발생하는 불편함 때문에 ModelGererator2를 사용한다.
def main():
    """
    메인 실행 함수입니다.
    커맨드 라인 인자를 파싱하고 전체 프로세스를 실행합니다.
    """
    parser = argparse.ArgumentParser(description="Generate C# model classes from MySQL CREATE TABLE statements.")
    parser.add_argument( "-f","--file", default="./SQL/create_table.sql",help="Path to the SQL file containing CREATE TABLE statements (default: ./SQL/create_table.sql)")
    # parser.add_argument("-o", "--output", default="./Model", help="Output directory for generated C# files (default: ./Model)")
    parser.add_argument("-o", "--output", default="../../API/Model", help="Output directory for generated C# files (default: ../../API/Model)")
    parser.add_argument("-n", "--namespace", default="API.Model", help="namespace for C# Model source files (default: API.Model)")

    args = parser.parse_args()

    try:
        mysql_query = SqlParser.read_sql_file(args.file)
        if not mysql_query:
            print("Failed to read SQL file. Please check the file path and try again.")
            return

        tables = SqlParser.parse_create_table(mysql_query)
        if not tables:
            print("No valid CREATE TABLE statements found in the SQL file.")
            return

        csharp_models = SqlParser.generate_csharp_models(tables, args.namespace)

        for model in csharp_models:
            print(model)
            print()

        SqlParser.save_models_to_files(csharp_models, args.output)  # 진짜 필요한 위치에 저장
        SqlParser.save_models_to_files(csharp_models, './Model')  # 출력 확인 용으로 저장(나중에 제거할 것)
        print(f"C# model files have been generated in the '{args.output}' directory.")

    except ValueError as ve:
        print(f"Parsing Error: {str(ve)}")
    except Exception as e:
        print(f"An unexpected error occurred: {str(e)}")

if __name__ == "__main__":
    main()