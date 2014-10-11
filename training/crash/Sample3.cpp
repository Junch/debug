#include <tchar.h>
#include <windows.h>

extern void PrintCallStack(const CONTEXT *pContext);

LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException)
{     
    PrintCallStack(pException->ContextRecord);

    return EXCEPTION_EXECUTE_HANDLER;
}

int _tmain(int argc, _TCHAR* argv[])  
{  
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);

    int i = 13;  
    int j = 0;  
    _tprintf(_T("The num is %d\n"), i/j);

    return 0;  
}
