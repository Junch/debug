#pragma once

#ifdef DLLSERVER
#define DLLSPEC __declspec(dllexport)
#else
#define DLLSPEC __declspec(dllimport)
#endif

DLLSPEC int add(int a, int b);
DLLSPEC int multiply(int a, int b);