#include <tchar.h>
#include <windows.h>
#include <dbghelp.h>

#pragma comment( lib, "DbgHelp" )

void CreateDumpFile(LPCWSTR lpstrDumpFilePathName, EXCEPTION_POINTERS *pException)
{
    HANDLE hDumpFile = CreateFile(lpstrDumpFilePathName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
    dumpInfo.ExceptionPointers = pException;
    dumpInfo.ThreadId = GetCurrentThreadId();
    dumpInfo.ClientPointers = TRUE;

    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);

    CloseHandle(hDumpFile);
}

LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException)
{     
    CreateDumpFile(_T("Test.dmp"), pException);

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
