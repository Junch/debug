// The example is from the book Assembly Language Succinctly

#include <stdio.h>
#include <stdlib.h>

extern "C" int FindSmallest(int* i, int count);

int main()
{
	int arr[] = {4, 2, -5, 3};

	printf("Smallest is %d\n", FindSmallest(arr, _countof(arr)));

	getchar();

	return 0;
}