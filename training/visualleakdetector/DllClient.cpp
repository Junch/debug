#include <tchar.h> 
#include <iostream>
#include "DllServer.h"
#pragma comment(lib, "DllServer")

void main(int argc, char* argv[])
{
    // No leak
    std::map<std::string, int> maps;
    getMap(maps);
    for (auto& elem: maps){
        printf("%s -> %d\n", elem.first.c_str(), elem.second);
    }

    // No leak
    std::map<std::string, std::string*> map2;
    getMap(map2);
    auto iter = map2.begin();
    while(iter != map2.end()){
        printf("%s -> %s\n", iter->first.c_str(), iter->second->c_str());
        delete iter->second;
        map2.erase(iter++);
    }

    // Leak now
    std::map<std::string, std::string*> map3;
    getMap(map3);

    int* arr = getArray();
    delete[] arr;
}
