!include <win32.mak>

all: DllServer.dll DllClient.exe
	DllClient.exe 3 4

DllServer.dll : DllServer.cpp DllServer.h
    cl /LD /MDd /Zi /nologo DllServer.cpp /DDLLSERVER /D_DEBUG /debug

DllClient.exe : DllClient.cpp
    cl /EHsc /Zi /nologo /MDd DllClient.cpp /D_DEBUG /debug

clean:
     @del *.obj *.exp *.manifest DllClient.exe DllServer.dll DllServer.lib
