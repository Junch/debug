#include <stdlib.h>
#include <stdio.h>

__declspec(noinline)
void func1() {
    printf("in func1\n");
}

__declspec(noinline)
int func2() {
    printf("in func2\n");
    func1();
    return 1;
}

__declspec(noinline)
int func3() {
    printf("in func3\n");
    func2();
    return 1;
}

int
main( int /*argc*/, char** /*argv*/ )
{
	func1();
	func2();
	func3();

    return 0;
}
