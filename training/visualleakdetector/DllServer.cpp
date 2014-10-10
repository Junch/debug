#include "DllServer.h"
#include "vld.h"

void getMap(std::map<std::string, int>& maps)
{
    maps["tom"]=2;
    maps["Peter"]=13;
}

void getMap(std::map<std::string, std::string*>& maps)
{
    maps["tom"]= new std::string("Good boy");
    maps["Peter"]=new std::string("Handsome guy");
}

int* getArray()
{
    return new int[12];
}
