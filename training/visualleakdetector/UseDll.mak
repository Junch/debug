!include <win32.mak>

all: DllServer.dll DllClient.exe
	DllClient.exe

DllServer.dll : DllServer.cpp DllServer.h
    cl /EHsc /Zi /nologo /MDd /LD DllServer.cpp /DDLLSERVER /D_DEBUG /debug

DllClient.exe : DllClient.cpp
    cl /EHsc /Zi /nologo /MDd DllClient.cpp /D_DEBUG /debug

clean:
     @del *.obj *.exp *.manifest DllClient.exe DllServer.dll DllServer.lib
