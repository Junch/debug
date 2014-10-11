#include <tchar.h>
#include <windows.h>
#include <dbghelp.h>
#include <atlstr.h>

#pragma comment( lib, "DbgHelp")
#pragma comment( lib, "user32")

CString GetPresentTime()
{  
     SYSTEMTIME time;  
     GetLocalTime(&time);   
  
     CString szTime;
     szTime.Format(_T("%04d-%02d-%02d %02d-%02d-%02d-%03d"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
     return szTime;
}

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

LONG CrashHandler(EXCEPTION_POINTERS *pException)
{   
    CString dumpFileName = GetPresentTime() +_T(".dmp");  

    CreateDumpFile(dumpFileName, pException);

    return EXCEPTION_EXECUTE_HANDLER;
}

int _tmain(int argc, _TCHAR* argv[])  
{
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)CrashHandler);

    __try
    {
        int i = 13;
        int j = 0;
        _tprintf(_T("The num is %d\n"), i/j);
    }
    __except(CrashHandler(GetExceptionInformation()))  
    {  
        MessageBox(NULL, _T("Message from '__except' section"), _T("Test"), MB_OK);
    }

    int *p = NULL;
    *p = 0;

    MessageBox(NULL, _T("Application completed"), _T("Test"), MB_OK);

    return 0;  
}
