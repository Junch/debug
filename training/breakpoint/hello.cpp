#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

__declspec(noinline)
void printHello(int i)
{
    printf(">> printHello\n");
    printf("%d, Hello World!\n",i);
    printf("<< printHello\n");
}

int
main( int /*argc*/, TCHAR** /*argv*/ )
{
    for (int i=0; i<10; ++i){
        printHello(i);
    }

    return 0;
}
