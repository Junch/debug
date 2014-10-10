#pragma once
#include <string>
#include <map>

#ifdef DLLSERVER
#define DLLSPEC __declspec(dllexport)
#else
#define DLLSPEC __declspec(dllimport)
#endif

DLLSPEC void getMap(std::map<std::string, int>& maps);
DLLSPEC void getMap(std::map<std::string, std::string*>& maps);
DLLSPEC int* getArray();
