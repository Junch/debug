This example is from the webpage http://blogs.msdn.com/b/ntdebugging/archive/2009/01/09/challenges-of-debugging-optimized-x64-code.aspx

rax, rcx, rdx, r8-r11 are volatile. 
rbx, rbp, rdi, rsi, r12-r15 are nonvolatile. 

Task: Get the first parameter to FunctionWith6Params.
1. Down the call graph
1.1 u example!FunctionWith6Params example!FunctionWith6Params+0x97 
    发现 mov r14d, ecx
1.2 u example!FunctionWith5Params example!FunctionWith5Params+0x20
    没有发现r14d
1.3 u example!FunctionWith4Params example!FunctionWith4Params+0x66
    发现 push    r14
1.4 k
    找到FunctionWith4Params和FunctionWith5Params的Child-SP
1.5 dps 00000000`0022fc60 00000000`0022fce0
    可以看到Push到Stack中的r14为0x29

2. Up the call graph
2.1 u example!main example!main+0x5b
    发现 mov     ecx,r14d
2.2 u example!FunctionWith6Params example!FunctionWith6Params+0x97 
    发现  push    r14
2.3 k
    找到main和FunctionWith6Params的Child-SP
2.4 dps  00000000`0022fd10 00000000`0022fd70
    可以看到Push到Stack中的r14为0x29