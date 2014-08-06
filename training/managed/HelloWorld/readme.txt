This example is from the book "Inside Windows Debugging" - Debugging Your First .NET Program using SOS

vercommand
.symfix c:\symbols
.reload
sxe ld clr
g
.lastevent
.loadby sos clr
!eeversion          ;Display the target CLR (execution engine) version.
!clrstack   -a      ;Display the managed frames in the current thread's call stack.

!bpmd mscorlib_ni System.Console.WriteLine  ;Set a breakpoint using a managed .NET method.
g
!u                  ;Display the disassembly of a managed function.
!dso                ;Display any managed objects it finds within the bounds of the current stack.
!do @rcx