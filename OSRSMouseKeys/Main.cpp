#include <iostream>
#include <Windows.h>
#include <WinUser.h>

// Get functions
int GetMouseSpeed()
{
	int mouseSpeed = -1;
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, &mouseSpeed, 0);
	return mouseSpeed;
}
bool GetEnhancePointerPrecisionState()
{
	int mouseParams[3];
	SystemParametersInfo(SPI_GETMOUSE, 0, mouseParams, 0);
	if (mouseParams[2] == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
MOUSEKEYS GetMouseKeys()
{
	MOUSEKEYS currentSettings;
	currentSettings.cbSize = sizeof(MOUSEKEYS);
	currentSettings.dwReserved1 = 0;
	currentSettings.dwReserved2 = 0;
	SystemParametersInfo(SPI_GETMOUSEKEYS, sizeof(MOUSEKEYS), &currentSettings, 0);
	return currentSettings;
}

// Set functions
void SetMouseSpeed(int newMouseSpeed)
{
	// Set the mouse speed.
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, (LPVOID)newMouseSpeed, 0);
}
void SetEnhancePointerPrecisionState(bool isON)
{
	// Get the current setup of the mouses acceleration, then turn off enhance pointer precision as this messes up the key jumps.
	int mouseParams[3];
	SystemParametersInfo(SPI_GETMOUSE, 0, mouseParams, 0);
	if (isON)
	{
		mouseParams[0] = 6;
		mouseParams[1] = 10;
	}
	else
	{
		mouseParams[0] = 0;
		mouseParams[1] = 0;
	}
	mouseParams[2] = isON;	// This sets the enhance pointer precision setting to off.
	SystemParametersInfo(SPI_SETMOUSE, 0, mouseParams, 0);
}
void SetMouseKeySettings(DWORD flags, DWORD topSpeed, DWORD acceleration)
{
	// Sets the new settings ready to pass to the OS.
	MOUSEKEYS newSettings;
	newSettings.cbSize = sizeof(MOUSEKEYS);
	newSettings.dwFlags = flags;
	newSettings.iMaxSpeed = topSpeed;
	newSettings.iTimeToMaxSpeed = acceleration;
	newSettings.iCtrlSpeed = 0;
	newSettings.dwReserved1 = 0;
	newSettings.dwReserved2 = 0;

	// Sets the system settings.
	SystemParametersInfo(SPI_SETMOUSEKEYS, sizeof(MOUSEKEYS), (LPVOID)&newSettings, 0);
}

// Program Main
int main()
{
	// Print the menu.
	std::cout 
		<< "---------------------------------------------------------------------------\n"
		<< "Welcome to Teebu's MouseKey Setup\n"
		<< "---------------------------------------------------------------------------\n" 
		<< "Please enter the Mousekey mode you wish to use:\n" 
		<< "Mode 0 - MouseKeys Off\n" 
		<< "Mode 1 - Drop Mode (Moves to menu option 2)\n" 
		<< "Mode 2 - Bank 'x' Mode (Moves to menu option 4)\n"
		<< "Mode 9 - Exit the program\n"
		<< "\n"
		<< "Please Input your choice:" 
		<< std::endl;

	bool isRunning = true;

	while (isRunning)
	{
		// Get the users input.
		int mode = 0;
		std::cin >> mode;


		if (mode == 0) {
			// Bank Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(true);
			SetMouseKeySettings(0, 184, 3000);
			std::cout << "MouseKeys have been turned off and the mouse settings have been reset." << std::endl;
		}
		else if (mode == 1) {
			// Drop Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 184, 3000);
			std::cout << "MouseKey Mode has been set to Drop mode." << std::endl;
		}
		else if (mode == 2) {
			// Bank (x) Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 358, 3000);
			std::cout << "MouseKey Mode has been set to Bank 'x' mode." << std::endl;
		}
		else if (mode == 9)
		{
			isRunning = false;
		}
	}
}
