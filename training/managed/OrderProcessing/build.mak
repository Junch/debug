!include <win32.mak>

all: OrderProcessing.exe

OrderProcessing.exe: OrderProcessing.cs
	%windir%\Microsoft.NET\Framework64\v4.0.30319\csc.exe /debug:pdbonly /o OrderProcessing.cs

clean:
     @del *.obj *.exp *.ilk *.exe *.dll *.lib *.pdb *.dmp
