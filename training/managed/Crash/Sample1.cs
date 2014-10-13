using System;

class Program
{
    static void Main(string[] args)
    {
        AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
        throw new ApplicationException("Something bad happened");
        Console.ReadLine();
    }

    static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
    {
        Exception theException = (Exception)e.ExceptionObject;
        Console.WriteLine(theException.ToString());
     
        // Exit to avoid unhandled exception dialog
        Environment.Exit(-1);
    }
}
