http://msdn.microsoft.com/en-us/library/windows/hardware/ff556853(v=vs.85).aspx

.restart

bp `hello!hello.cpp:9`

bp `hello!hello.cpp:9` ".if(@ebx=6){} .else{gc}"

bp hello!printHello ".if(@ecx=6){} .else{gc}"

bp hello!printHello ".printf \"%p\\n\", @rcx; gc"

bp `hello!hello.cpp:9` ".if(@ebx%3=0){} .else{gc}"

bp `hello!hello.cpp:9` "$$<commands.txt"