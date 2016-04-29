#include <stdio.h>

__declspec(noinline) 
int add(int a, int b)
{
	return a + b;
}

int main()
{
    printf("Hello, world!\n");

#ifdef DEBUG
    printf("Debug version\n");
#endif

    int x = 7, y = 8;
    printf("%d + %d = %d\n", x, y, add(x, y));
}
