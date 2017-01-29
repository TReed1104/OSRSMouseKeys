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
MOUSEKEYS GetMouseKeySettings()
{
	MOUSEKEYS currentSettings;
	currentSettings.cbSize = sizeof(MOUSEKEYS);
	currentSettings.dwReserved1 = 0;
	currentSettings.dwReserved2 = 0;
	SystemParametersInfo(SPI_GETMOUSEKEYS, sizeof(MOUSEKEYS), &currentSettings, 0);
	return currentSettings;
}
STICKYKEYS GetStickyKeySettings()
{
	STICKYKEYS currentSettings;
	currentSettings.cbSize = sizeof(STICKYKEYS);
	SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &currentSettings, 0);
	return currentSettings;
}

// Set functions
void SetMouseSpeed(int newMouseSpeed)
{
	// Set the mouse speed.
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, (LPVOID)newMouseSpeed, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
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
	SystemParametersInfo(SPI_SETMOUSE, 0, mouseParams, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
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
	SystemParametersInfo(SPI_SETMOUSEKEYS, sizeof(MOUSEKEYS), (LPVOID)&newSettings, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
void SetStickKeySettings(DWORD flags)
{
	// Sets the new settings ready to pass to the OS.
	STICKYKEYS newSettings;
	newSettings.cbSize = sizeof(STICKYKEYS);
	newSettings.dwFlags = flags;
	// Sets the system settings.
	SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), (LPVOID)&newSettings, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}

// Program Main
int main()
{
	// Draw the UI.
	std::cout 
		<< "----------------------------------------------------------------------------------------\n"
		<< "Welcome to Teebu's MouseKey Setup\n"
		<< "----------------------------------------------------------------------------------------\n" 
		<< "This program is open-source and comes with absolutely no warranty, the user takes full\n"
		<< "responsibility for any actions and issues encountered.\n"
		<< "----------------------------------------------------------------------------------------\n"
		<< "Please enter the Mousekey mode you wish to use:\n" 
		<< "Command >> 'reset'		>> Disables MouseKeys.\n"
		<< "Command >> 'drop'		>> Drop mode, without Sticky Keys.\n"
		<< "Command >> 'bank'		>> Bank 'x' mode, without Sticky Keys.\n"
		<< "Command >> 'drop sticky'	>> Drop mode, with Sticky Keys.\n"
		<< "Command >> 'bank sticky'	>> Bank 'x' mode, with Sticky Keys.\n"
		<< "Command >> 'exit'		>> Close the program.\n"
		<< "\n"
		<< "**Please note that sticky key modes still require you to double tap Ctrl like normal.\n"
		<< "\n"
		<< "----------------------------------------------------------------------------------------\n"
		<< std::endl;



	bool isProgramRunning = true;
	while (isProgramRunning)
	{
		std::cout << "Please Input the mode you wish to activate..." << std::endl;
		// Get the users input.
		std::string enteredCommand;
		std::getline(std::cin, enteredCommand);

		if (enteredCommand == "reset") {
			// Bank Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(true);
			SetMouseKeySettings(0, 184, 3000);
			SetStickKeySettings(0);
			std::cout << "MouseKeys have been turned off and the mouse settings have been reset.\n" << std::endl;
		}
		else if (enteredCommand == "drop") {
			// Drop Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 184, 3000);
			SetStickKeySettings(0);
			std::cout << "MouseKey Mode has been set to Drop mode.\n" << std::endl;
		}
		else if (enteredCommand == "bank") {
			// Bank (x) Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 358, 3000);
			SetStickKeySettings(0);
			std::cout << "MouseKey Mode has been set to Bank 'x' mode.\n" << std::endl;
		}
		else if (enteredCommand == "drop sticky") {
			// Drop Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 184, 3000);
			SetStickKeySettings((SKF_AUDIBLEFEEDBACK | SKF_AVAILABLE | SKF_STICKYKEYSON | SKF_INDICATOR | SKF_TRISTATE));
			std::cout << "MouseKey Mode has been set to Drop mode, using Sticky Keys.\n" << std::endl;
		}
		else if (enteredCommand == "bank sticky") {
			// Bank (x) Mode.
			SetMouseSpeed(10);
			SetEnhancePointerPrecisionState(false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 358, 3000);
			SetStickKeySettings((SKF_AUDIBLEFEEDBACK | SKF_AVAILABLE | SKF_STICKYKEYSON | SKF_INDICATOR | SKF_TRISTATE));
			std::cout << "MouseKey Mode has been set to Bank 'x' mode, using Sticky Keys.\n" << std::endl;
		}
		else if (enteredCommand == "exit")
		{
			std::cout << "Exit of the program initialised, clearing up and closing.\n" << std::endl;
			isProgramRunning = false;
		}
		else
		{
			std::cout << "Unknown input, pease try again.\n" << std::endl;
		}
	}
}
