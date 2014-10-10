#include <tchar.h> 
#include <iostream>
#include "DllServer.h"
#pragma comment(lib, "DllServer")

void main(int argc, char* argv[])
{
    std::map<std::string, int> maps;
    getMap(maps);
    for (auto& elem: maps){
        printf("%s -> %d\n", elem.first.c_str(), elem.second);
    }

    int* arr = getArray();
    delete[] arr;
}
