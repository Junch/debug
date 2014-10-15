using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Show Params in Windbg");
        Program p = new Program();

        p.ShowParams(123456, "TestParams", 'L');
        Console.ReadLine();
    }

    public void ShowParams(int a, string b ,char c)
    {
        Console.WriteLine(b);
    }
}
