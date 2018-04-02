#include "Program.h"

Program* program;	// Our Mouse Keys program

// Function to handle the program being close by events other than inputs, to prevent memory leaking
static BOOL WINAPI closeHandlerRoutine(DWORD dwCtrlType)
{
	switch (dwCtrlType)
	{
		case CTRL_C_EVENT:			// Ctrl+C
			delete program;
			return TRUE;
		case CTRL_BREAK_EVENT:		// Ctrl+Break
			delete program;
			return TRUE;
		case CTRL_CLOSE_EVENT:		// Closing the console window
			delete program;
			return TRUE;
		case CTRL_LOGOFF_EVENT:		// User logs off. Passed only to services!
			delete program;
			return TRUE;
		case CTRL_SHUTDOWN_EVENT:	// System is shutting down. Passed only to services!
			delete program;
			return TRUE;
	}
	return FALSE;
}

// Program main
int main() {
	SetConsoleCtrlHandler(closeHandlerRoutine, TRUE);

	program = new Program();	
	program->Run();
	delete program;
}
