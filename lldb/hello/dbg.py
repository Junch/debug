import sys
import os

# Specify location of the lldb module (or add this to PYTHONPATH environment variable)
python_path_to_lldb = '/Applications/Xcode.app/Contents/SharedFrameworks/LLDB.framework/Resources/Python'
sys.path.append(python_path_to_lldb)
import lldb

if __name__ == "__main__":
    dbg = lldb.SBDebugger.Create()
    dbg.SetAsync(False)
    #target = dbg.CreateTarget("DebugMac")
    target = dbg.CreateTargetWithFileAndArch ("hello", lldb.LLDB_ARCH_DEFAULT)
    target.BreakpointCreateByName("main", target.GetExecutable().GetFilename())
    target.BreakpointCreateByName("sayHello", target.GetExecutable().GetFilename())
    process = target.LaunchSimple(None, None, os.getcwd())

    while(process.GetState() != lldb.eStateExited):
        if (process.GetState() == lldb.eStateStopped):
            for thread in process:
                print 'LldbExecutor: Stack trace for thread: (%d)' % thread.GetIndexID()
                for frame in thread:
                    print frame

        # print "Current state: " + dbg.StateAsCString(process.GetState())
        print "\n"
        process.Continue()

    remaining_stdout = process.GetSTDOUT(1000)
    print remaining_stdout
    exit_status = process.GetExitStatus()
    print 'Exit status from process under debug is', exit_status

    process.Destroy()
    dbg.DeleteTarget(target)
    dbg.Terminate()