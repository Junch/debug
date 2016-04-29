import os, sys
import pykd

class ExceptionHandler(pykd.eventHandler):
    def __init__(self):
        pykd.eventHandler.__init__(self)

    def onException(self, exceptionInfo):
        print "onException"
        return pykd.eventResult.NoChange

    def onBreakpoint(self, id):
        print "onBreakpoint {}".format(id)
        stack = pykd.dbgCommand("kb")
        print stack
        return pykd.eventResult.NoChange

    def onThreadStart(self):
        print "Thread starts"
        return pykd.eventResult.NoChange

    def onThreadStop(self):
        print "Thread stop"
        return pykd.eventResult.NoChange

    def onLoadModule(self, base, name):
        print "onLoadModule " + name
        return pykd.eventResult.NoChange

    def onUnloadModule(self, base, name):
        print "onUnloadModule " + name
        return pykd.eventResult.NoChange

class callCounter(object):
    def __init__(self):
        self.count = 0
    def __call__(self):
        self.count = self.count + 1
        return pykd.eventResult.Proceed

def main():
    pykd.initialize()
    pykd.handler = ExceptionHandler()
    pykd.startProcess("hello.exe")
    targetModule = pykd.module("hello")
    targetModule.reload()

    breakCount = callCounter()
    b1 = pykd.setBp(targetModule.offset('add'), breakCount) # The b1 cannot be commented
    print "There is %d breakpoint" % pykd.getNumberBreakpoints()

    pykd.go()
    print breakCount.count

    targetModule = None
    pykd.killAllProcesses()

if __name__ == "__main__":
    main()