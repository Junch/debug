#include <iostream>
#include "vld.h"

void mem_leak()
{
    int * p = new int[100];
    int * p1 = new int[20];

	for (int i = 0; i < 3; i++)
    	int *ptr = new int(100);

    delete [] p;
}

int main()
{
    mem_leak();
    return 0;
}
