#include <stdlib.h>
#include <stdio.h>

int gNumber = 0;

__declspec(noinline)
void printHello(int i)
{
    printf(">> printHello\n");
    printf("%d, Hello World!\n",i);
    gNumber = i;
    printf("<< printHello\n");
}

__declspec(noinline)
int getNumber(int i) {
    return 2*i+1;
}

int
main( int /*argc*/, char** /*argv*/ )
{
    for (int i=0; i<10; ++i){
        printHello(getNumber(i));
    }

    return 0;
}
