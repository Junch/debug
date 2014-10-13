!include <win32.mak>

all: Sample1.exe Sample2.exe

Sample1.exe : Sample1.cs
	%windir%\Microsoft.NET\Framework64\v4.0.30319\csc.exe /debug:pdbonly /o Sample1.cs

Sample2.exe : Sample2.cs
	%windir%\Microsoft.NET\Framework64\v4.0.30319\csc.exe /debug:pdbonly /o Sample2.cs

clean:
     @del *.obj *.exp *.ilk *.exe *.dll *.lib *.pdb *.dmp
