#include <tchar.h> 
#include <iostream>
#include "DllServer.h"
#include "vld.h"
#pragma comment(lib, "DllServer")

void main(int argc, char* argv[])
{
    std::cout << _T("Calling methods from DllServer.DLL:\n");
    
    if (argc != 3)
    {
        std::cout << _T("Usage: DllClient <num1> <num2>\n");
        return;
    }
    
    int num1 = _tstoi(argv[1]);
    int num2 = _tstoi(argv[2]);

    int *leak = new int[10];
    
    int sum = add(num1, num2);
    int product = multiply(num1, num2);
    std::cout << num1 << _T(" + ")
              << num2 << _T(" = ")
              << sum  << std::endl;
    
    std::cout << num1 << _T(" * ")
              << num2 << _T(" = ")
              << product  << std::endl;
}
