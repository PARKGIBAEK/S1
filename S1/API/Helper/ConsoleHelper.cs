namespace API.Helper;

public static class ConsoleHelper
{

    public static void PrintSuccessMessage(string message)
    {
        // 텍스트 색상을 초록색으로 변경
        Console.ForegroundColor = ConsoleColor.Green;
        Console.WriteLine(message);
        // 기본 색상으로 되돌림
        Console.ResetColor();
    }

    public static void PrintFailMessage(string message)
    {
        // 텍스트 색상을 빨강색으로 변경
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine(message);
        // 기본 색상으로 되돌림
        Console.ResetColor();
    }

}
