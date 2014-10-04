http://support2.microsoft.com/kb/286470
http://msdn.microsoft.com/en-us/library/windows/hardware/ff549557(v=vs.85).aspx

Page Heap选项位于注册表目录：HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\你的可执行程序名\。当Windows开始启动一个进程时，Window通过检查这个注册表目录的设置，对该进程应用相应的PageHeap选项。

禁止page heap
gflags.exe /p /disable heap.exe

配置正常页堆
gflags.exe /p /enable heap.exe

配置完全页堆，注意进程名不能带路径
gflags.exe /p /enable heap.exe /full

非对齐方式启用完全页堆
gflags.exe /p /enable heap.exe /full /unaligned

查询
gflags /i heap.exe 

正常页堆
正常页堆原理与CRT调试内存分配函数类似，通过分配少量的填充信息，在释放内存块时检查填充区域。来检测内存是否被损坏，此方法的优点是极大的减少了内存耗用量。缺点是只能在释放块时检测，不太好跟踪出错的代码位置。

完全页堆：

当分配一块内存时，通过调整内存块的分配位置，使其结尾恰好与系统分页边界对齐，然后在边界处再多分配一个不可访问的页作为保护区域。这样，一旦出现内存读/写越界时，进程就会Crash，从而帮助及时检查内存越界。