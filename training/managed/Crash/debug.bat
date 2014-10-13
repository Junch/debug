REM The batch file is to open the dumpfile created by sample2.exe
windbg -z UnhandledDump.dmp -c ".load %windir%\Microsoft.NET\Framework64\v4.0.30319\sos.dll;!clrstack"