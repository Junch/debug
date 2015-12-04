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
bp hello!getNumber "gu; .if (@rax=0x7){} .else {gc}"

Set the return value of getNumber to be 10
bp hello!getNumber "gu; r rax=0n10; g"

Skip execution of a function
bu hello!printHello "r rip = poi(@rsp); r rsp = @rsp + 0x8; .echo hello!getNumber skipped; g"

Skip execution of printHello when the parameter is larger than 11
bu hello!printHello ".if (@ecx > 0n11) {r rip=poi(@rsp); r rsp=@rsp+0x8}; gc"

Break when the gNumber is set to 13
hello!gNumber ".if (dwo(hello!gNumber) == 0n13) {} .else {gc}"

Show the stack content
dps @rsp
