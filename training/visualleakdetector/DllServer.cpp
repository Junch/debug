#include "DllServer.h"
#include "vld.h"

void getMap(std::map<std::string, int>& maps)
{
    int *leak = new int[50];
    maps["tom"]=2;
    maps["Peter"]=13;
}

int* getArray()
{
    return new int[12];
}
