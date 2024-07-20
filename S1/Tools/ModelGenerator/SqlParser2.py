def convert_to_csharp_type(mysql_type):
    """
    MySQL ������ Ÿ���� C# ������ Ÿ������ ��ȯ�մϴ�.
    
    :param mysql_type: MySQL ������ Ÿ��
    :return: �ش��ϴ� C# ������ Ÿ��
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

    return 'object'  # ��Ī�Ǵ� Ÿ���� ���� ��� �⺻��

def parse_create_table(sql):
    """
    SQL CREATE TABLE ���� �Ľ��Ͽ� ���̺� ������ �����մϴ�.
    
    :param sql: SQL CREATE TABLE ���� ���Ե� ���ڿ�
    :return: �Ľ̵� ���̺� ������ ���� ��ųʸ�
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

            # NOT NULL ���� Ȯ��
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
    �Ľ̵� ���̺� ������ �������� C# �� Ŭ������ �����մϴ�.
    
    :param tables: �Ľ̵� ���̺� ���� ����
    :param model_namespace: �� Ŭ������ ���ӽ����̽�
    :return: ������ C# �� Ŭ���� ���ڿ� ����Ʈ
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
    ������ C# �� Ŭ�������� ������ ���Ϸ� �����մϴ�.
    
    :param models: ������ C# �� Ŭ���� ���ڿ� ����Ʈ
    :param output_directory: ���ϵ��� ������ ���丮 ���
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
    SQL ������ �о� ������ ���ڿ��� ��ȯ�մϴ�.
    ���� ���ڵ��� �õ��մϴ�.
    
    :param file_path: SQL ������ ���
    :return: SQL ������ ���� (���ڿ�)
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
