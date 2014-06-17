#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

__declspec(noinline)
void
FunctionWith4Params( int param1, int param2, int param3,
                     int param4 )
{
    size_t lotsOfLocalVariables1 = rand();
    size_t lotsOfLocalVariables2 = rand();
    size_t lotsOfLocalVariables3 = rand();
    size_t lotsOfLocalVariables4 = rand();
    size_t lotsOfLocalVariables5 = rand();
    size_t lotsOfLocalVariables6 = rand();
    DebugBreak();
    printf( "Entering FunctionWith4Params( %X, %X, %X, %X )\n",
            param1, param2, param3, param4 );
    printf( "Local variables: %X, %X, %X, %X, %X, %X \n",
            lotsOfLocalVariables1, lotsOfLocalVariables2,
            lotsOfLocalVariables3, lotsOfLocalVariables4,
            lotsOfLocalVariables5, lotsOfLocalVariables6 );
}
__declspec(noinline)
void
FunctionWith5Params( int param1, int param2, int param3,
                     int param4, int param5 )
{
    FunctionWith4Params( param5, param4, param3, param2 );
    FunctionWith4Params( rand(), rand(), rand(), rand() );
}
__declspec(noinline)
void
FunctionWith6Params( int param1, int param2, int param3,
                     int param4, int param5, int param6 )
{
    size_t someLocalVariable1 = rand();
    size_t someLocalVariable2 = rand();
    printf( "Entering %s( %X, %X, %X, %X, %X, %X )\n",
            "FunctionWith6Params",
            param1, param2, param3, param4, param5, param6 );
    FunctionWith5Params( rand(), rand(), rand(),
                         param1, rand() );
    printf( "someLocalVariable1 = %X, someLocalVariable2 = %X\n",
            someLocalVariable1, someLocalVariable2 );
}
int
main( int /*argc*/, TCHAR** /*argv*/ )
{
    // I use the rand() function throughout this code to keep
    // the compiler from optimizing too much.  If I had used
    // constant values, the compiler would have optimized all
    // of these away.
    int params[] = { rand(), rand(), rand(),
                     rand(), rand(), rand() };
    FunctionWith6Params( params[0], params[1], params[2],
                         params[3], params[4], params[5] );
    return 0;
}
