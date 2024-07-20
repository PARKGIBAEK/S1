def convert_to_csharp_type(mysql_type):
    """
    MySQL 데이터 타입을 C# 데이터 타입으로 변환합니다.
    
    :param mysql_type: MySQL 데이터 타입
    :return: 해당하는 C# 데이터 타입
    """
    type_mapping = {
        'INT': 'int',
        'TINYINT': 'sbyte',
        'SMALLINT': 'short',
        'MEDIUMINT': 'int',
        'BIGINT': 'long',
        'FLOAT': 'float',
        'DOUBLE': 'double',
        'DECIMAL': 'decimal',
        'CHAR': 'string',
        'VARCHAR': 'string',
        'TINYTEXT': 'string',
        'TEXT': 'string',
        'MEDIUMTEXT': 'string',
        'LONGTEXT': 'string',
        'BINARY': 'byte[]',
        'VARBINARY': 'byte[]',
        'TINYBLOB': 'byte[]',
        'BLOB': 'byte[]',
        'MEDIUMBLOB': 'byte[]',
        'LONGBLOB': 'byte[]',
        'DATE': 'DateTime',
        'DATETIME': 'DateTime',
        'TIMESTAMP': 'DateTime',
        'TIME': 'TimeSpan',
        'YEAR': 'short',
        'BIT': 'bool',
        'ENUM': 'string',
        'SET': 'string',
        'JSON': 'string'
    }

    for key in type_mapping:
        if mysql_type.upper().startswith(key):
            return type_mapping[key]

    return 'object'  # 매칭되는 타입이 없을 경우 기본값

def parse_create_table(sql):
    """
    SQL CREATE TABLE 문을 파싱하여 테이블 구조를 추출합니다.
    
    :param sql: SQL CREATE TABLE 문이 포함된 문자열
    :return: 파싱된 테이블 구조를 담은 딕셔너리
    """
    tables = {}
    current_table = None
    in_create_table = False

    for line_number, line in enumerate(sql.split('\n'), 1):
        line = line.strip()

        if line.upper().startswith('CREATE TABLE'):
            in_create_table = True
            match = re.search(r'CREATE TABLE (\w+)', line, re.IGNORECASE)
            if not match:
                raise ValueError(f"Invalid CREATE TABLE statement at line {line_number}: {line}")
            current_table = match.group(1)
            tables[current_table] = []
        elif line.startswith(')'):
            in_create_table = False
            current_table = None
        elif in_create_table and current_table and line and not line.startswith('--'):
            if re.match(r'^(INDEX|CONSTRAINT|FOREIGN\s+KEY)', line, re.IGNORECASE):
                continue

            column_match = re.search(r'(\w+)\s+(\w+(\(\d+\))?)(.*)', line)
            if not column_match:
                continue

            column_name = column_match.group(1)
            column_type = column_match.group(2).split('(')[0]
            options = column_match.group(4)

            csharp_type = convert_to_csharp_type(column_type.upper())
            is_primary_key = 'PRIMARY KEY' in options.upper()
            is_auto_increment = 'AUTO_INCREMENT' in options.upper()
            has_default = 'DEFAULT' in options.upper()

            # NOT NULL 조건 확인
            is_not_null = ('NOT NULL' in options.upper() or
                           is_primary_key or
                           is_auto_increment or
                           has_default)

            column_info = {
                'name': column_name,
                'type': csharp_type,
                'is_nullable': not is_not_null,
                'is_primary_key': is_primary_key,
                'is_auto_increment': is_auto_increment
            }

            tables[current_table].append(column_info)

    return tables

def generate_csharp_models(tables, model_namespace):
    """
    파싱된 테이블 정보를 바탕으로 C# 모델 클래스를 생성합니다.
    
    :param tables: 파싱된 테이블 구조 정보
    :param model_namespace: 모델 클래스의 네임스페이스
    :return: 생성된 C# 모델 클래스 문자열 리스트
    """
    models = []
    for table_name, columns in tables.items():
        class_name = table_name
        model = f"using System;\n\nnamespace {model_namespace};\n\npublic class {class_name}\n{{\n"

        for column in columns:
            csharp_type = column['type']
            if column['is_nullable']:
                if csharp_type in ['int', 'long', 'short', 'decimal', 'double', 'float', 'bool', 'DateTime']:
                    csharp_type += '?'

            model += f"    public {csharp_type} {column['name']} {{ get; set; }}\n"

        model += "}"
        models.append(model)
    return models


def save_models_to_files(models, output_directory):
    """
    생성된 C# 모델 클래스들을 각각의 파일로 저장합니다.
    
    :param models: 생성된 C# 모델 클래스 문자열 리스트
    :param output_directory: 파일들을 저장할 디렉토리 경로
    """
    if not os.path.exists(output_directory):
        os.makedirs(output_directory)

    for model in models:
        class_name = re.search(r'public class (\w+)', model).group(1)
        file_name = f"{class_name}.cs"
        file_path = os.path.join(output_directory, file_name)

        with open(file_path, 'w') as file:
            file.write(model)

        print(f"Created file: {file_path}")

def read_sql_file(file_path):
    """
    SQL 파일을 읽어 내용을 문자열로 반환합니다.
    여러 인코딩을 시도합니다.
    
    :param file_path: SQL 파일의 경로
    :return: SQL 파일의 내용 (문자열)
    """
    encodings = ['utf-8', 'euc-kr', 'cp949']

    for encoding in encodings:
        try:
            with open(file_path, 'r', encoding=encoding) as file:
                return file.read()
        except UnicodeDecodeError:
            continue
        except IOError as e:
            print(f"Error reading SQL file: {e}")
            return None

    print(f"Failed to decode the file with encodings: {encodings}")
    return None
