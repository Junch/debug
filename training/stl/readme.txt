http://blogs.msdn.com/b/ambrosew/archive/2013/01/15/debugging-stl-containers-with-windbg-part-1-vector.aspx
http://0cch.net/wordpress/?p=460
http://blogs.microsoft.co.il/sasha/2013/07/25/displaying-and-searching-stdmap-contents-in-windbg/
http://letsexplorewindows.blogspot.hk/2013/12/debugging-map-using-windbg.html

0:000> dt ss
Local var @ 0x1ffe70 Type std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >
   +0x000 _Myfirst         : 0x00000000`003fc0d0 std::basic_string<char,std::char_traits<char>,std::allocator<char> >
   +0x008 _Mylast          : 0x00000000`003fc130 std::basic_string<char,std::char_traits<char>,std::allocator<char> >
   +0x010 _Myend           : 0x00000000`003fc130 std::basic_string<char,std::char_traits<char>,std::allocator<char> >


0:000> dt myvector!std::basic_string<char,std::char_traits<char>,std::allocator<char> >
这个命令用来计算长度

也可以用下面这个命令
0:000> ?? sizeof(std::basic_string<char,std::char_traits<char>,std::allocator<char> >)

第一个元素
0:000> dt -r 0x00000000`003fc0d0  std::basic_string<char,std::char_traits<char>,std::allocator<char> >
container!std::basic_string<char,std::char_traits<char>,std::allocator<char> >
   +0x000 _Bx              : std::_String_val<std::_Simple_types<char> >::_Bxty
      +0x000 _Buf             : [16]  "1"
      +0x000 _Ptr             : 0xbaadf00d`baad0031  "--- memory read error at address 0xbaadf00d`baad0031 ---"
      +0x000 _Alias           : [16]  "1"
   +0x010 _Mysize          : 1
   +0x018 _Myres           : 0xf
   =00000001`3fe00000 npos             : 0x3`00905a4d

第二个元素
0:000> dt -r 0x00000000`003fc0d0+0x20  std::basic_string<char,std::char_traits<char>,std::allocator<char> >
container!std::basic_string<char,std::char_traits<char>,std::allocator<char> >
   +0x000 _Bx              : std::_String_val<std::_Simple_types<char> >::_Bxty
      +0x000 _Buf             : [16]  "2"
      +0x000 _Ptr             : 0xbaadf00d`baad0032  "--- memory read error at address 0xbaadf00d`baad0032 ---"
      +0x000 _Alias           : [16]  "2"
   +0x010 _Mysize          : 1
   +0x018 _Myres           : 0xf
   =00000001`3fe00000 npos             : 0x3`00905a4d



0:000> $$>a<mapstring.wds mymap -c ".block{?? @$t9.first;?? @$t9.second._Bx}"
