import argparse
import model_generator


def main():
    #  argparse모듈로 command line arguments를 파싱
    parser = argparse.ArgumentParser(description="Generate C# model classes from MySQL CREATE TABLE statements.")
    parser.add_argument("-f", "--file", default="../../DB/SQL/create_table.sql",
                        help="Path to the SQL file containing CREATE TABLE statements (default: ../../DB/SQL/create_table.sql)")
    parser.add_argument("-o", "--output", default="../../API/Model",
                        help="Output directory for generated C# files (default: ../../API/Model)")
    parser.add_argument("-n", "--namespace", default="API.Model",
                        help="namespace for C# Model source files (default: API.Model)")

    args = parser.parse_args()

    try:
        mysql_query = model_generator.read_sql_file(args.file)
        if not mysql_query:
            print("Failed to read SQL file. Please check the file path and try again.")
            return

        tables = model_generator.parse_create_table(mysql_query)
        if not tables:
            print("No valid CREATE TABLE statements found in the SQL file.")
            return

        csharp_models = model_generator.generate_csharp_models(tables, args.namespace)

        for model in csharp_models:
            print(model)
            print()

        print("DbContext Configuration:")

        model_generator.save_models_to_files(csharp_models, args.output)

        print(f"C# model files and DbContext configuration have been generated in the '{args.output}' directory.")

    except ValueError as ve:
        print(f"Parsing Error: {str(ve)}")
    except Exception as e:
        print(f"An unexpected error occurred: {str(e)}")


if __name__ == "__main__":
    main()
