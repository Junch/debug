#include <stdio.h>

int main(int argc, char* argv[])
{
     char *p = new char[8];
     p[8] = 10;

     delete[] p;
     return 0;
}
