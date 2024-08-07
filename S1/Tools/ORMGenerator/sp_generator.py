# coding=utf-8
from typing import List
from column_info import ColumnInfo
from jinja2 import Template

from stored_procedures import StoredProcedure


class SPGenerator:
    @staticmethod
    def SP_INSERT(*, sp_name: str, table_name: str, insert_params: List[ColumnInfo]) -> str:
        template_str = """
CREATE PROCEDURE {{sp_name}}(
    {% for param in insert_params %}IN new_{{param.column_name}} {{param.data_type_with_length}}{% if not loop.last %},\n    {% endif %}{% endfor %}
)
BEGIN
    INSERT INTO {{table_name}}
    {% for col in insert_params %} {{col.column_name}}{% if not loop.last %}, {% endif %}{% endfor %} 
    ({% for param in insert_params %}new_{{param.column_name}}{% if not loop.last %}, {% endif %}{% endfor %})
    VALUES ({% for param in insert_params %}new_{{param.column_name}}{% if not loop.last %}, {% endif %}{% endfor %});
END
"""
        jinja_template = Template(template_str)
        return jinja_template.render(sp_name=sp_name, insert_params=insert_params, table_name=table_name)


    @staticmethod
    def SP_INSERT2(*, sp: StoredProcedure) -> str:
        template_str = """
CREATE PROCEDURE {{sp.sp_name}}(
    {% for params in insert_params %}IN new_{{param.column_name}} {{param.data_type_with_length}}{% if not loop.last %},\n    {% endif %}{% endfor %}
)
BEGIN
    INSERT INTO {{sp.table_name}}
    ({% for col in insert_params %}new_{{col.column_name}}{% if not loop.last %}, {% endif %}{% endfor %})
    VALUES ({% for param in insert_params %}new_{{param.column_name}}{% if not loop.last %}, {% endif %}{% endfor %});
END
"""
        jinja_template = Template(template_str)
        return jinja_template.render(sp_name=sp.sp_name, insert_params=sp.insert_params, table_name=sp.table_name)


    @staticmethod
    def SP_SELECT(*, sp_name: str, table_name: str, select_where_params: List[ColumnInfo],
                  select_params: List[ColumnInfo]) -> str:
        template_str = """
CREATE PROCEDURE {{sp_name}}(
    {% if where_params %}{% for param in where_params %}IN w_{{param.column_name}} {{param.data_type_with_length}}{% if not loop.last %},\n    {% endif %}{% endfor %}{% endif %}
)
BEGIN
    SELECT {% if select_params %}{% for col in select_params %}{{col.column_name}}{% if not loop.last %}, {% endif %}{% endfor %}{% else %}*{% endif %}
    FROM {{table_name}}
    {% if where_params %}WHERE {% for col in where_params %} {{col.column_name}} = w_{{col.column_name}}{% if not loop.last %},\n          {% endif %}{% endfor %};{% endif %}
END
"""
        jinja_template = Template(template_str)
        return jinja_template.render(sp_name=sp_name, table_name=table_name, where_params=select_where_params,
                                     select_columns=select_params)


#     @staticmethod
#     def SP_SELECT2(*, sp: StoredProcedure) -> str:
#
#         template_str = f"""
# CREATE PROCEDURE {sp.sp_name}(
#     {select_where_param}
# )
# BEGIN
#     SELECT {select_param}
#     FROM {sp.table_name}
#     {where_clause}
#
# END
# """


    @staticmethod
    def SP_UPDATE(*, sp_name: str, table_name: str, update_where_params: List[ColumnInfo],
                  update_set_params: List[ColumnInfo]) -> str:
        template_str = """
CREATE PROCEDURE {{sp_name}}(
    {% for param in where_params %}IN w_{{param.column_name}} {{param.data_type_with_length}}{% if not loop.last %},\n    {% endif %}{% endfor %},\n
    {% for param in update_params %}IN new_{{param.column_name}} {{param.data_type_with_length}}{% if not loop.last %},\n    {% endif %}{% endfor %},\n
)
BEGIN
    UPDATE {{table_name}}
    SET {% for col in update_params %}{{col.column_name}} = new_{{col.column_name}}{% if not loop.last %},\n        {% endif %}{% endfor %}
    WHERE {% for col in where_params %} {{col.column_name}} = w_{{col.column_name}}{% if not loop.last %},\n          {% endif %}{% endfor %};
END
"""
        jinja_template = Template(template_str)
        return jinja_template.render(sp_name=sp_name, table_name=table_name, where_params=update_where_params,
                                     update_params=update_set_params)


    @staticmethod
    def SP_DELETE(*, sp_name: str, table_name: str, delete_where_params: List[ColumnInfo]) -> str:
        template_str = """
CREATE PROCEDURE {{sp_name}}(
    {% for param in where_params %}IN w_{{param.column_name}} {{param.data_type_with_length}}{% if not loop.last %},\n    {% endif %}{% endfor %}
)
BEGIN
    DELETE FROM {{table_name}}
    WHERE {% for col in where_params %} {{col.column_name}} = w_{{col.column_name}}{% if not loop.last %},\n          {% endif %}{% endfor %};
END
"""
        jinja_template = Template(template_str)
        return jinja_template.render(sp_name=sp_name, table_name=table_name, where_params=delete_where_params)


    def SP_DELETE22(self):
        return f"""
CREATE PROCEDURE {{sp_name}}(
    {{select_params}}
)
BEGIN
    DELETE FROM {{table_name}}
    WHERE {{where_columns}};
END
"""


    @property
    def Transaction(self):
        return Template("""
CREATE PROCEDURE {{ sp_name }}({% for param in params %}IN {{ param.name }} {{ param.type }}{% if not loop.last %}, {% endif %}{% endfor %})
BEGIN
    DECLARE exit handler for sqlexception
    BEGIN
        ROLLBACK;
        RESIGNAL;
    END;

    START TRANSACTION;

    {% for query in queries %}
    {{ query }};
    {% endfor %}

    COMMIT;
END;
""")


def test_sp():
    insert_params: List[ColumnInfo] = [
        ColumnInfo(table_name='user_account', column_name='id', column_id=1, data_type='INT'),
        ColumnInfo(table_name='user_account', column_name='user_name', column_id=2, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='password', column_id=3, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='email', column_id=4, data_type='VARCHAR', max_length=64)
    ]

    sp_insert_template = SPGenerator.SP_INSERT(sp_name='sp_1', table_name='user_account',
                                               insert_params=insert_params,
                                               insert_columns=insert_params)
    print("SP_INSERT TEMPLATE : ")
    print(sp_insert_template)

    where_params1: List[ColumnInfo] = [
        ColumnInfo(table_name='user_account', column_name='id', column_id=1, data_type='INT'),
        ColumnInfo(table_name='user_account', column_name='user_name', column_id=2, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='password', column_id=3, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='email', column_id=4, data_type='VARCHAR', max_length=64)
    ]

    select_columns: List[ColumnInfo] = [
        ColumnInfo(table_name='user_account', column_name='id', column_id=1, data_type='INT'),
        ColumnInfo(table_name='user_account', column_name='user_name', column_id=2, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='password', column_id=3, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='email', column_id=4, data_type='VARCHAR', max_length=64)
    ]

    sp_select_template = SPGenerator.SP_SELECT(sp_name='sp_2', table_name='user_account',
                                               select_where_params=where_params1,
                                               select_params=select_columns)
    print("SP_SELECT TEMPLATE : ")
    print(sp_select_template)

    where_params2: List[ColumnInfo] = [
        ColumnInfo(table_name='user_account', column_name='id', column_id=1, data_type='INT'),
        ColumnInfo(table_name='user_account', column_name='user_name', column_id=2, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='password', column_id=3, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='email', column_id=4, data_type='VARCHAR', max_length=64)
    ]

    update_columns: List[ColumnInfo] = [
        ColumnInfo(table_name='user_account', column_name='id', column_id=1, data_type='INT'),
        ColumnInfo(table_name='user_account', column_name='user_name', column_id=2, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='password', column_id=3, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='email', column_id=4, data_type='VARCHAR', max_length=64)
    ]

    sp_update_template = SPGenerator.SP_UPDATE(sp_name='sp_3', table_name='user_account',
                                               update_where_params=where_params2,
                                               update_set_params=update_columns)
    print("SP_UPDATE TEMPLATE : ")
    print(sp_update_template)

    where_params3: List[ColumnInfo] = [
        ColumnInfo(table_name='user_account', column_name='id', column_id=1, data_type='INT'),
        ColumnInfo(table_name='user_account', column_name='user_name', column_id=2, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='password', column_id=3, data_type='VARCHAR', max_length=32),
        ColumnInfo(table_name='user_account', column_name='email', column_id=4, data_type='VARCHAR', max_length=64)
    ]

    sp_delete_template = SPGenerator.SP_DELETE(sp_name='sp_3', table_name='user_account',
                                               delete_where_params=where_params3)
    print("SP_DELETE TEMPLATE : ")
    print(sp_delete_template)

# test_sp()
