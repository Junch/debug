This example is from the book "Advanced .NET Debugging"

可参考文章
http://www.cnblogs.com/lbq1221119/archive/2008/10/17/1313677.html
Windbg在Managed App中设置函数断点的几种方法


0:000> !loadby sos clr

在没有JIT编译的函数上设置断点

0:000> !name2ee *!Advanced.NET.Debugging.Chapter3.Breakpoint.AddAndPrint
Module:      000007fe8dd92f98
Assembly:    03Breakpoint.exe
Token:       0000000006000002
MethodDesc:  000007fe8dd93930
Name:        Advanced.NET.Debugging.Chapter3.Breakpoint.AddAndPrint(Int32, Int32)
Not JITTED yet. Use !bpmd -md 000007fe8dd93930 to break on run.

0:000> !bpmd -md 000007fe8dd93930
MethodDesc = 000007fe8dd93930
Adding pending breakpoints...

0:000> g
(3d20.3c08): CLR notification exception - code e0444143 (first chance)
JITTED 03Breakpoint!Advanced.NET.Debugging.Chapter3.Breakpoint.AddAndPrint(Int32, Int32)
Setting breakpoint: bp 000007FE8DEB021B [Advanced.NET.Debugging.Chapter3.Breakpoint.AddAndPrint(Int32, Int32)]
Breakpoint 0 hit
000007fe`8deb021b 8d341a          lea     esi,[rdx+rbx]

0:000> !dso
OS Thread Id: 0x3c08 (0)
RSP/REG          Object           Name
rcx              0000000002725c90 Advanced.NET.Debugging.Chapter3.Breakpoint
000000000026EC30 0000000002722d48 System.String    Press any key (1st instance function)
000000000026EC60 0000000002722d48 System.String    Press any key (1st instance function)
000000000026EC70 0000000002725c90 Advanced.NET.Debugging.Chapter3.Breakpoint
000000000026ECD0 0000000002722d28 System.Object[]    (System.String[])
000000000026EE08 0000000002722d28 System.Object[]    (System.String[])
000000000026EF28 0000000002722d28 System.Object[]    (System.String[])
000000000026F0E8 0000000002722d28 System.Object[]    (System.String[])
000000000026F108 00000000027221b0 System.Security.Policy.Evidence

0:000> !do 0000000002725c90
Name:        Advanced.NET.Debugging.Chapter3.Breakpoint
MethodTable: 000007fe8dd93958
EEClass:     000007fe8dea2220
Size:        24(0x18) bytes
File:        D:\Github\debug\training\managed\Breakpoint\03Breakpoint.exe
Fields:
None

0:000> !clrstack
OS Thread Id: 0x3c08 (0)
        Child SP               IP Call Site
000000000026ec10 000007fe8deb021b Advanced.NET.Debugging.Chapter3.Breakpoint.AddAndPrint(Int32, Int32) [d:\Github\debug\training\managed\Breakpoint\03Breakpoint.cs @ 37]
000000000026ec70 000007fe8deb0119 Advanced.NET.Debugging.Chapter3.Breakpoint.Main(System.String[]) [d:\Github\debug\training\managed\Breakpoint\03Breakpoint.cs @ 21]
000000000026efb0 000007feed52ffe3 [GCFrame: 000000000026efb0] 