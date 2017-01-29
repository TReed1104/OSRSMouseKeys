#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

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
		<< "Enter 'reset' to disable MouseKeys.\n"
		<< "Enter 'drop' for Dropping mode - Moves the mouse to the second menu option.\n"
		<< "Enter 'bank' for Banking mode - Moves the mouse to the fourth menu option.\n"
		<< "Enter 'exit' to close the program.\n"
		<< "\n"
		<< "Please Input your choice:" 
		<< std::endl;

	bool isRunning = true;

	while (isRunning)
	{
		// Get the users input.
		std::string enteredCommand;
		std::getline(std::cin, enteredCommand);

		if (enteredCommand == "reset") {
			// Bank Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(true);
			SetMouseKeySettings(0, 184, 3000);
			std::cout << "MouseKeys have been turned off and the mouse settings have been reset." << std::endl;
		}
		else if (enteredCommand == "drop") {
			// Drop Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 184, 3000);
			std::cout << "MouseKey Mode has been set to Drop mode." << std::endl;
		}
		else if (enteredCommand == "bank") {
			// Bank (x) Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 358, 3000);
			std::cout << "MouseKey Mode has been set to Bank 'x' mode." << std::endl;
		}
		else if (enteredCommand == "exit")
		{
			isRunning = false;
		}
		else
		{
			std::cout << "Unknown input, pease try again." << std::endl;
		}
	}
}
