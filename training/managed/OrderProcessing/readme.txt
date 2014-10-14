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
