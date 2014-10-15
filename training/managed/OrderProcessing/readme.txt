http://blogs.microsoft.co.il/sasha/2014/08/05/motivating-example-windbg-scripting-net-developers/

0:000> !Name2EE OrderProcessing!OrderProcessing.Order
Module:      000007fe8dda2f98
Assembly:    OrderProcessing.exe
Token:       0000000002000002
MethodTable: 000007fe8dda3a50
EEClass:     000007fe8deb22b8
Name:        OrderProcessing.Order

0:000> !dumpheap -mt 000007fe8dda3a50 -short
0000000002782df8
0000000002785208
0000000002785290
0000000002785318
00000000027853a0
0000000002785488
...

0:000> !dumpobj 0000000002785318
Name:        OrderProcessing.Order
MethodTable: 000007fe8dda3a50
EEClass:     000007fe8deb22b8
Size:        32(0x20) bytes
File:        D:\Github\debug\training\managed\OrderProcessing\OrderProcessing.exe
Fields:
              MT    Field   Offset                 Type VT     Attr            Value Name
000007fedf1492b0  4000001       10         System.Int32  1 instance                3 <CustomerId>k__BackingField
000007fedf146500  4000002        8        System.String  0 instance 0000000002785370 <ProductName>k__BackingField

0:000> !dumpobj 0000000002785370
Name:        System.String
MethodTable: 000007fedf146500
EEClass:     000007fedea63750
Size:        46(0x2e) bytes
File:        C:\WINDOWS\Microsoft.Net\assembly\GAC_64\mscorlib\v4.0_4.0.0.0__b77a5c561934e089\mscorlib.dll
String:      Product #3
Fields:
              MT    Field   Offset                 Type VT     Attr            Value Name
000007fedf1492b0  40000aa        8         System.Int32  1 instance               10 m_stringLength
000007fedf1477e8  40000ab        c          System.Char  1 instance               50 m_firstChar
000007fedf146500  40000ac       18        System.String  0   shared           static Empty
                                 >> Domain:Value  00000000000b4080:NotInit  <<

0:000> !Name2EE OrderProcessing!OrderProcessing.Program.Main
Module:      000007fe8dda2f98
Assembly:    OrderProcessing.exe
Token:       0000000006000006
MethodDesc:  000007fe8dda3920
Name:        OrderProcessing.Program.Main(System.String[])
JITTED Code Address: 000007fe8dec0090

0:000> !U 000007fe8dec0090
Normal JIT generated code
OrderProcessing.Program.Main(System.String[])
Begin 000007fe8dec0090, size c4

d:\Github\debug\training\managed\OrderProcessing\OrderProcessing.cs @ 16:
>>> 000007fe`8dec0090 53              push    rbx
000007fe`8dec0091 55              push    rbp
000007fe`8dec0092 56              push    rsi
000007fe`8dec0093 57              push    rdi
000007fe`8dec0094 4883ec38        sub     rsp,38h
000007fe`8dec0098 488d0d413aeeff  lea     rcx,[000007fe`8dda3ae0]
...

0:000> !dumpil 000007fe8dda3920
ilAddr = 000000000138207c
IL_0000: newobj class [mscorlib]System.Collections.Generic.List`1<????::.ctor 
IL_0005: stloc.0 
IL_0006: ldc.i4.0 
IL_0007: stloc.1 
IL_0008: br.s IL_0038
IL_000a: ldloc.0 
IL_000b: newobj OrderProcessing.Order::.ctor
IL_0010: stloc.2 
IL_0011: ldloc.2 
IL_0012: ldloc.1 
IL_0013: callvirt OrderProcessing.Order::set_CustomerId
IL_0018: ldloc.2 
IL_0019: ldstr "Product #"
IL_001e: ldloc.1 
IL_001f: box System.Int32
IL_0024: call System.String::Concat 
IL_0029: callvirt OrderProcessing.Order::set_ProductName
IL_002e: ldloc.2 
IL_002f: callvirt class [mscorlib]System.Collections.Generic.List`1<????::Add 
IL_0034: ldloc.1 
IL_0035: ldc.i4.1 
IL_0036: add 
IL_0037: stloc.1 
IL_0038: ldloc.1 
IL_0039: ldc.i4.s 100
IL_003b: blt.s IL_010a
IL_003d: call System.Console::ReadLine 
IL_0042: pop 
IL_0043: ldloc.0 
IL_0044: call System.GC::KeepAlive 
IL_0049: ret 
