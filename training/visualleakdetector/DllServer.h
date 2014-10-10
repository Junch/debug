#pragma once
#include <string>
#include <map>

#ifdef DLLSERVER
#define DLLSPEC __declspec(dllexport)
#else
#define DLLSPEC __declspec(dllimport)
#endif

DLLSPEC void getMap(std::map<std::string, int>& maps);
DLLSPEC int* getArray();
