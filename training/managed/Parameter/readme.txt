http://www.cnblogs.com/lbq1221119/archive/2008/10/17/1313679.html
Windbg寻找Managed Founction参数值

为了避免inline函数，程序采用debug模式编译

0:000> !name2ee *!Program.ShowParams
Module:      000007fededf1000
Assembly:    mscorlib.dll
--------------------------------------
Module:      000007fe8dda2f98
Assembly:    example.exe
Token:       0000000006000002
MethodDesc:  000007fe8dda3930
Name:        Program.ShowParams(Int32, System.String, Char)
JITTED Code Address: 000007fe8dec01a0

0:000> !bpmd -md 000007fe8dda3930
MethodDesc = 000007fe8dda3930
Setting breakpoint: bp 000007FE8DEC01A0 [Program.ShowParams(Int32, System.String, Char)]


---------------------------------------
0:000> !threads
ThreadCount:      2
UnstartedThread:  0
BackgroundThread: 1
PendingThread:    0
DeadThread:       0
Hosted Runtime:   no
                                                                                                        Lock  
       ID OSID ThreadOBJ           State GC Mode     GC Alloc Context                  Domain           Count Apt Exception
   0    1 3f04 000000000065e7f0    2a020 Cooperative 0000000002345B48:0000000002345FD0 00000000005f3fa0 0     MTA 
   2    2 2240 000000000064dfa0    2b220 Preemptive  0000000000000000:0000000000000000 00000000005f3fa0 0     MTA (Finalizer) 

0:000> !dumpdomain 00000000005f3fa0
--------------------------------------
Domain 1:           00000000005f3fa0
LowFrequencyHeap:   00000000005f4758
HighFrequencyHeap:  00000000005f47e0
StubHeap:           00000000005f4868
Stage:              OPEN
SecurityDescriptor: 00000000005f7180
Name:               example.exe
Assembly:           000000000067e8a0 [C:\WINDOWS\Microsoft.Net\assembly\GAC_64\mscorlib\v4.0_4.0.0.0__b77a5c561934e089\mscorlib.dll]
ClassLoader:        000000000067e9e0
SecurityDescriptor: 00000000006782a0
  Module Name
000007fededf1000            C:\WINDOWS\Microsoft.Net\assembly\GAC_64\mscorlib\v4.0_4.0.0.0__b77a5c561934e089\mscorlib.dll

Assembly:           000000000068bff0 [D:\Github\debug\training\managed\Parameter\example.exe]
ClassLoader:        000000000068c190
SecurityDescriptor: 000000000068ba30
  Module Name
000007fe8dda2f98            D:\Github\debug\training\managed\Parameter\example.exe

0:000> !dumpmodule -mt 000007fe8dda2f98
Name:       D:\Github\debug\training\managed\Parameter\example.exe
Attributes: PEFile 
Assembly:   000000000068bff0
LoaderHeap:              0000000000000000
TypeDefToMethodTableMap: 000007fe8dda0070
TypeRefToMethodTableMap: 000007fe8dda0088
MethodDefToDescMap:      000007fe8dda00c0
FieldDefToDescMap:       000007fe8dda00e0
MemberRefToDescMap:      000007fe8dda00e8
FileReferencesMap:       000007fe8dda0128
AssemblyReferencesMap:   000007fe8dda0130
MetaData start address:  000000000012209c (872 bytes)

Types defined in this module

              MT          TypeDef Name
------------------------------------------------------------------------------
000007fe8dda3948 0x02000002 Program

Types referenced in this module

              MT            TypeRef Name
------------------------------------------------------------------------------
000007fedf4d6ae0 0x02000001 System.Object
000007fedf4caf90 0x02000006 System.Console

0:000> !dumpmt -md 000007fe8dda3948
EEClass:         000007fe8deb2220
Module:          000007fe8dda2f98
Name:            Program
mdToken:         0000000002000002
File:            D:\Github\debug\training\managed\Parameter\example.exe
BaseSize:        0x18
ComponentSize:   0x0
Slots in VTable: 7
Number of IFaces in IFaceMap: 0
--------------------------------------
MethodDesc Table
           Entry       MethodDesc    JIT Name
000007fedf26e110 000007fedee02e10 PreJIT System.Object.ToString()
000007fedf279a10 000007fedee02e18 PreJIT System.Object.Equals(System.Object)
000007fedf279520 000007fedee02e40 PreJIT System.Object.GetHashCode()
000007fedf27a6c0 000007fedee02e58 PreJIT System.Object.Finalize()
000007fe8dec0150 000007fe8dda3940    JIT Program..ctor()
000007fe8dec0090 000007fe8dda3920    JIT Program.Main(System.String[])
000007fe8dec01a0 000007fe8dda3930    JIT Program.ShowParams(Int32, System.String, Char)

0:000> !clrstack -p
OS Thread Id: 0x3f04 (0)
        Child SP               IP Call Site
00000000003ee8d0 000007fe8dec01cd Program.ShowParams(Int32, System.String, Char) [d:\Github\debug\training\managed\Parameter\example.cs @ 15]
    PARAMETERS:
        this (0x00000000003ee900) = 0x0000000002345b30
        a (0x00000000003ee908) = 0x000000000001e240
        b (0x00000000003ee910) = 0x0000000002342d50
        c (0x00000000003ee918) = 0x000000000000004c

00000000003ee900 000007fe8dec0123 Program.Main(System.String[]) [d:\Github\debug\training\managed\Parameter\example.cs @ 10]
    PARAMETERS:
        args (0x00000000003ee950) = 0x0000000002342ce8

00000000003eec30 000007feed52ffe3 [GCFrame: 00000000003eec30] 

0:000> !do 0x0000000002342d50
Name:        System.String
MethodTable: 000007fedf4d6500
EEClass:     000007fededf3750
Size:        46(0x2e) bytes
File:        C:\WINDOWS\Microsoft.Net\assembly\GAC_64\mscorlib\v4.0_4.0.0.0__b77a5c561934e089\mscorlib.dll
String:      TestParams
Fields:
              MT    Field   Offset                 Type VT     Attr            Value Name
000007fedf4d92b0  40000aa        8         System.Int32  1 instance               10 m_stringLength
000007fedf4d77e8  40000ab        c          System.Char  1 instance               54 m_firstChar
000007fedf4d6500  40000ac       18        System.String  0   shared           static Empty
                                 >> Domain:Value  00000000005f3fa0:NotInit  <<
0:000> .formats 0x000000000001e240
Evaluate expression:
  Hex:     00000000`0001e240
  Decimal: 123456
  Octal:   0000000000000000361100
  Binary:  00000000 00000000 00000000 00000000 00000000 00000001 11100010 01000000
  Chars:   .......@
  Time:    Fri Jan 02 18:17:36 1970
  Float:   low 1.72999e-040 high 0
  Double:  6.09954e-319

0:000> .formats 0x000000000000004c
Evaluate expression:
  Hex:     00000000`0000004c
  Decimal: 76
  Octal:   0000000000000000000114
  Binary:  00000000 00000000 00000000 00000000 00000000 00000000 00000000 01001100
  Chars:   .......L
  Time:    Thu Jan 01 08:01:16 1970
  Float:   low 1.06499e-043 high 0
  Double:  3.7549e-322
