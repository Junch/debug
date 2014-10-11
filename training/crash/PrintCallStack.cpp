#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#ifdef UNICODE
#define DBGHELP_TRANSLATE_TCHAR
#endif
#include <dbghelp.h>

#pragma comment(lib, "dbghelp.lib")

void PrintCallStack(const CONTEXT *pContext)
{
    HANDLE hProcess = GetCurrentProcess();
    SymInitialize(hProcess, NULL, TRUE);
    CONTEXT c = *pContext;

    STACKFRAME64 sf;
    memset(&sf, 0, sizeof(STACKFRAME64));
    DWORD dwImageType = IMAGE_FILE_MACHINE_I386;

#ifdef _M_IX86
    sf.AddrPC.Offset = c.Eip;
    sf.AddrPC.Mode = AddrModeFlat;
    sf.AddrStack.Offset = c.Esp;
    sf.AddrStack.Mode = AddrModeFlat;
    sf.AddrFrame.Offset = c.Ebp;
    sf.AddrFrame.Mode = AddrModeFlat;
#elif _M_X64
    dwImageType = IMAGE_FILE_MACHINE_AMD64;
    sf.AddrPC.Offset = c.Rip;
    sf.AddrPC.Mode = AddrModeFlat;
    sf.AddrFrame.Offset = c.Rsp;
    sf.AddrFrame.Mode = AddrModeFlat;
    sf.AddrStack.Offset = c.Rsp;
    sf.AddrStack.Mode = AddrModeFlat;
#elif _M_IA64
    dwImageType = IMAGE_FILE_MACHINE_IA64;
    sf.AddrPC.Offset = c.StIIP;
    sf.AddrPC.Mode = AddrModeFlat;
    sf.AddrFrame.Offset = c.IntSp;
    sf.AddrFrame.Mode = AddrModeFlat;
    sf.AddrBStore.Offset = c.RsBSP;
    sf.AddrBStore.Mode = AddrModeFlat;
    sf.AddrStack.Offset = c.IntSp;
    sf.AddrStack.Mode = AddrModeFlat;
#else
    #error "Platform not supported!"
#endif

    HANDLE hThread = GetCurrentThread();

    while (true)
    {
        if (!StackWalk64(dwImageType, hProcess, hThread, &sf, &c, NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL))
            break;

        DWORD64 address = sf.AddrPC.Offset;
        if (address == 0)
            break;
       
        // Get symbol name
        char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)] = {0};
        PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)buffer;
        pSymbol->MaxNameLen = MAX_SYM_NAME ;
        pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        SymFromAddr(hProcess, address, NULL, pSymbol);

        // Get module name
        IMAGEHLP_MODULE64 moduleInfo = {0};
        moduleInfo.SizeOfStruct = sizeof(IMAGEHLP_MODULE64);
        TCHAR* szModule = _T("");
        // SymGetModuleInfo64 will fail in unicode version
        // http://msdn.microsoft.com/en-us/library/windows/desktop/ms681336(v=vs.85).aspx
        if (SymGetModuleInfo64(hProcess, address, &moduleInfo))
            szModule = moduleInfo.ModuleName;

        // Get file name and line count
        IMAGEHLP_LINE64 lineInfo = {0};
        lineInfo.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
        DWORD displacement;
        if (SymGetLineFromAddr64(hProcess, address, &displacement, &lineInfo))
        {
            _tprintf(_T("%016llX %s!%s [%s @ %lu]\n"), pSymbol->Address, szModule, pSymbol->Name, lineInfo.FileName, lineInfo.LineNumber);
        }
        else
        {
            _tprintf(_T("%016llX %s!%s\n"), pSymbol->Address, szModule, pSymbol->Name);
        }
    }

    SymCleanup(hProcess);
}
