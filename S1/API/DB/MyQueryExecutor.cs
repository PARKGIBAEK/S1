﻿using MySqlConnector;

namespace API.DB;

public static class MyQueryExecutor
{
    // SQL 파일 실행 함수
    public static void ExecuteSqlScript(string connectionString, string filePath)
    {
        var sqlFile = File.ReadAllText(filePath);
        using var connection = new MySqlConnection(connectionString);
        connection.Open();
        using var command = new MySqlCommand(sqlFile, connection);
        command.ExecuteNonQuery();
    }
}