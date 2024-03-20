using System.Collections.Generic;

public static class DataStorage
{
    public static Stack<string> StringStack { get; } = new Stack<string>();
    public static Queue<string> StringQueue { get; } = new Queue<string>();
}
