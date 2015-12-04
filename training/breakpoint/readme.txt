http://msdn.microsoft.com/en-us/library/windows/hardware/ff556853(v=vs.85).aspx

.restart

bp `hello!hello.cpp:11`

bp `hello!hello.cpp:11` ".if(@ebx=6){} .else{gc}"

bp hello!printHello ".if(@ecx=6){} .else{gc}"

bp hello!printHello ".printf \"%p\\n\", @rcx; gc"

bp `hello!hello.cpp:11` ".if(@ebx%3=0){} .else{gc}"

bp `hello!hello.cpp:11` "$$<commands.txt"

bp 00000001`3f411034 "r @rip=00000001`3f411042; gc"

Break when the function return 7
bp hello!getNumber "gu; .if (@rax=7){} .else {gc}"

Skip execution of a function
bu hello!printHello "r rip = poi(@rsp); r rsp = @rsp + 0x8; .echo hello!getNumber skipped; g"

Show the stack content
dps @rsp
