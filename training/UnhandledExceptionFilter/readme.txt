http://msdn.microsoft.com/en-us/library/windows/desktop/ms681401(v=vs.85).aspx

0:000> u kernel32!unhandledexceptionfilter
kernel32!UnhandledExceptionFilter:
00000000`76b5b7e0 488bc4          mov     rax,rsp
00000000`76b5b7e3 48894808        mov     qword ptr [rax+8],rcx
00000000`76b5b7e7 53              push    rbx
00000000`76b5b7e8 56              push    rsi
00000000`76b5b7e9 57              push    rdi
00000000`76b5b7ea 4154            push    r12
00000000`76b5b7ec 4155            push    r13
00000000`76b5b7ee 4156            push    r14

0:000> knL 10
 # Child-SP          RetAddr           Call Site
00 00000000`00199b88 00000000`76c04bc4 user32!ZwUserWaitMessage+0xa
01 00000000`00199b90 00000000`76c04edd user32!DialogBox2+0x274
02 00000000`00199c20 00000000`76c52920 user32!InternalDialogBox+0x135
03 00000000`00199c80 00000000`76c51c15 user32!SoftModalMessageBox+0x9b4
04 00000000`00199db0 00000000`76c5146b user32!MessageBoxWorker+0x31d
05 00000000`00199f70 00000000`76c51362 user32!MessageBoxTimeoutW+0xb3
06 00000000`0019a040 00000001`3fc4d377 user32!MessageBoxW+0x4e
07 00000000`0019a080 000007fe`e66ffb3a acad!AcadMessageBox::show+0x127
08 00000000`0019a140 000007fe`e6ab33a0 accore!msg_box+0x17a
09 00000000`0019a220 000007fe`e6a4ca8b accore!safeMsgBox+0x10
0a 00000000`0019a250 000007fe`e6a4c810 accore!erabtv+0x26b
0b 00000000`0019a680 000007fe`e6ab287c accore!erabt+0x20
0c 00000000`0019a6b0 00000000`76b5b940 accore!acadUnhandledExceptionFilter+0x13c
0d 00000000`0019a6f0 00000000`76d73398 kernel32!UnhandledExceptionFilter+0x160
0e 00000000`0019a7d0 00000000`76cf85c8 ntdll! ?? ::FNODOBFM::`string'+0x2365
0f 00000000`0019a800 00000000`76d09d2d ntdll!_C_specific_handler+0x8c

0:000> dp 00000000`0019a7d0 L1
00000000`0019a7d0  00000000`0019a830

0:000> dp 00000000`0019a830 L2
00000000`0019a830  00000000`0019b470 00000000`0019af80

0:000> .exr 00000000`0019b470
ExceptionAddress: 000007fee654aa0f (accore!selectionPreviewInterruptCallback+0x000000000000000f)
   ExceptionCode: c0000005 (Access violation)
  ExceptionFlags: 00000000
NumberParameters: 2
   Parameter[0]: 0000000000000000
   Parameter[1]: ffffffffffffffff
Attempt to read from address ffffffffffffffff

0:000> .cxr 00000000`0019af80
rax=000007fee654aa00 rbx=0000000028bbbbe0 rcx=880000aa71fe4b5e
rdx=00000000289ac290 rsi=000000000019b7d0 rdi=00000000289ac290
rip=000007fee654aa0f rsp=000000000019b680 rbp=000000000019b700
 r8=000000000019b700  r9=000000000019b7d0 r10=0000000047e33521
r11=000000003f221515 r12=0000000022808140 r13=000000002ebd5340
r14=000007fee654aa00 r15=000000000000031d
iopl=0         nv up ei ng nz na pe nc
cs=0033  ss=002b  ds=002b  es=002b  fs=0053  gs=002b             efl=00010282
accore!selectionPreviewInterruptCallback+0xf:
000007fe`e654aa0f 488b11          mov     rdx,qword ptr [rcx] ds:880000aa`71fe4b5e=????????????????

写了一个脚本restore.wds，执行下面的命令就可以了
0:000> $$>a<restore.wds 00000000`0019a7d0
