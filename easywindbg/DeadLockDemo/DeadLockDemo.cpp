///////////////////////////////////////////////////////////////////////////////
//
// DeadLockDemo.cpp
//
// Author: Oleg Starodumov (www.debuginfo.com)
//
// This application simulates a deadlock 
//
//


///////////////////////////////////////////////////////////////////////////////
// Include files 
//

#include <windows.h>
#include <tchar.h>

#include <process.h>
#include <stdio.h>


///////////////////////////////////////////////////////////////////////////////
// Helper macros 
//

// _beginthreadex wrapper macro (source: J.Richter, "Advanced Windows")

typedef unsigned (__stdcall *PTHREAD_START) (void*);

#define BEGINTHREADEX(lpsa, cbStack, lpStartAddr,\
	lpvThreadParm, fdwCreate, lpIDThread)          \
		((HANDLE)_beginthreadex(                     \
				(void*)(lpsa),                           \
				(unsigned)(cbStack),                     \
				(PTHREAD_START)(lpStartAddr),            \
				(void*)(lpvThreadParm),                  \
				(unsigned)(fdwCreate),                   \
				(unsigned*)(lpIDThread)))


///////////////////////////////////////////////////////////////////////////////
// Critical section wrapper classes 
// 

class CCriticalSection 
{
public: 

	CCriticalSection()
	{
		InitializeCriticalSection( &m_cs );
	}

	~CCriticalSection()
	{
		DeleteCriticalSection( &m_cs );
	}

	void Lock()
	{
		EnterCriticalSection( &m_cs );
	}

	void Unlock()
	{
		LeaveCriticalSection( &m_cs );
	}

private: 

	// Copy protection 
	CCriticalSection( const CCriticalSection& );
	CCriticalSection& operator=( const CCriticalSection& );

private: 

	// Critical section structure 
	CRITICAL_SECTION m_cs; 
};

class CCritSecLock 
{
public: 

	CCritSecLock( CCriticalSection& cs ) 
	: m_rcs( cs )
	{
		m_rcs.Lock(); 
	}

	~CCritSecLock()
	{
		m_rcs.Unlock(); 
	}

private: 

	// CCriticalSection object reference 
	CCriticalSection& m_rcs; 
};


///////////////////////////////////////////////////////////////////////////////
// Function declarations 
//

DWORD WINAPI ThreadOne( LPVOID lpParam );
DWORD WINAPI ThreadTwo( LPVOID lpParam );


///////////////////////////////////////////////////////////////////////////////
// Global variables 
//

CCriticalSection CritSecOne;
CCriticalSection CritSecTwo;


///////////////////////////////////////////////////////////////////////////////
// main()
//

int _tmain( int argc, TCHAR* argv[] )
{
	// Start worker threads 

	_tprintf( _T("Starting worker threads...\n") );

	HANDLE  hThread   = NULL;
	DWORD   ThreadId  = 0;

	hThread = BEGINTHREADEX(0, 0, ThreadOne, 0, 0, &ThreadId );

	if( hThread == NULL )
	{
		_tprintf( _T("Cannot start thread. Error: %u\n"), GetLastError() );
		return 0;
	}

	hThread = BEGINTHREADEX(0, 0, ThreadTwo, 0, 0, &ThreadId );

	if( hThread == NULL )
	{
		_tprintf( _T("Cannot start thread. Error: %u\n"), GetLastError() );
		return 0;
	}


	// Worker threads started 

	_tprintf( _T("Worker threads started.\n") );

	Sleep( 60 * 60 * 1000 );


	// Complete 

	_tprintf( _T("Test complete.\n") );

	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Worker threads 
//

DWORD WINAPI ThreadOne( LPVOID lpParam )
{
	_tprintf( _T("ThreadOne[%u] started.\n"), GetCurrentThreadId() );

	while( 1 ) 
	{
		CCritSecLock LockOne( CritSecOne );

		_tprintf( _T("ThreadOne[%u] acquired CritSecOne\n"), GetCurrentThreadId() );

		{
			CCritSecLock LockTwo( CritSecTwo );

			_tprintf( _T("ThreadOne[%u] acquired CritSecTwo.\n"), GetCurrentThreadId() );
		}
	}

	return 0;
}

DWORD WINAPI ThreadTwo( LPVOID lpParam )
{
	_tprintf( _T("ThreadTwo[%u] started.\n"), GetCurrentThreadId() );

	while( 1 ) 
	{
		CCritSecLock LockTwo( CritSecTwo );

		_tprintf( _T("ThreadTwo[%u] acquired CritSecTwo\n"), GetCurrentThreadId() );

		{
			CCritSecLock LockOne( CritSecOne );

			_tprintf( _T("ThreadTwo[%u] acquired CritSecOne\n"), GetCurrentThreadId() );
		}
	}

	return 0;
}

