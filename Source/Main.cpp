#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

// Get functions
int GetMouseSpeed() {
	// Creates an int to hold the data passed back by the Windows SPI API.
	int mouseSpeed = -1;

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, &mouseSpeed, 0);
	return mouseSpeed;
}
void GetMouseSettings(const int inputArray[]) {
	// Creates an array to hold the data passed back by the Windows SPI API.
	int mouseParams[3];

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETMOUSE, 0, mouseParams, 0);
	inputArray = mouseParams;
}
MOUSEKEYS GetMouseKeySettings() {
	// Creates an appropriate struct to hold the data passed back by the Windows SPI API.
	MOUSEKEYS currentSettings;
	currentSettings.cbSize = sizeof(MOUSEKEYS);
	currentSettings.dwReserved1 = 0;
	currentSettings.dwReserved2 = 0;

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETMOUSEKEYS, sizeof(MOUSEKEYS), &currentSettings, 0);
	return currentSettings;
}
STICKYKEYS GetStickyKeySettings() {
	// Creates an appropriate struct to hold the data passed back by the Windows SPI API.
	STICKYKEYS currentSettings;
	currentSettings.cbSize = sizeof(STICKYKEYS);

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &currentSettings, 0);
	return currentSettings;
}

// Set functions
void SetMouseSpeed(const int &newMouseSpeed) {
	// Passes the new value to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, (LPVOID)newMouseSpeed, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
void SetMouseSettings(const int &mouseThresholdX, const int &mouseThresholdY, const bool &enablePointerPrecisionState) {
	// Creates and fills an array with the new settings.
	int mouseParams[3];
	mouseParams[0] = mouseThresholdX;
	mouseParams[1] = mouseThresholdY;
	mouseParams[2] = (int)enablePointerPrecisionState;	// This sets the enhance pointer precision setting to off.

	// Passes the array to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSE, 0, mouseParams, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
void SetMouseKeySettings(const DWORD &flags, const DWORD &topSpeed, const DWORD &acceleration) {
	// Creates and fills an appropriate struct with the new settings.
	MOUSEKEYS newSettings;
	newSettings.cbSize = sizeof(MOUSEKEYS);
	newSettings.dwFlags = flags;
	newSettings.iMaxSpeed = topSpeed;
	newSettings.iTimeToMaxSpeed = acceleration;
	newSettings.iCtrlSpeed = 0;
	newSettings.dwReserved1 = 0;
	newSettings.dwReserved2 = 0;

	// Passes the struct to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSEKEYS, sizeof(MOUSEKEYS), (LPVOID)&newSettings, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
void SetStickKeySettings(const DWORD &flags) {
	// Creates and fills an appropriate struct with the new settings.
	STICKYKEYS newSettings;
	newSettings.cbSize = sizeof(STICKYKEYS);
	newSettings.dwFlags = flags;

	// Passes the struct to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), (LPVOID)&newSettings, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}

// Console outputs
void PrintDisclaimers() {
	std::cout
		<< "Teebu's Mouse Key control panel\n"
		<< "A client for the quick setup of your Operating Systems Mouse Keys.\n\n"

		<< "DISCLAIMER:\n"
		<< "This project is an Open-Source client for the quick and easy toggling between the different\n"
		<< "mouse key modes commonly used for Old School Runescape.\n"
		<< "This program sets the Operating system's mouse key settings directly and therefore does not\n"
		<< "break the rules set out by Jagex.\n"
		<< std::endl;
}
void PrintCommands() {
	// Draw the UI.
	std::cout
		<< "COMMANDS:\n"
		<< "Command >> '0' or 'reset'		>> Disables MouseKeys.\n"
		<< "Command >> '1' or 'drop'		>> Drop mode, without Sticky Keys.\n"
		<< "Command >> '2' or 'drop sticky'		>> Drop mode, with Sticky Keys (see FAQ).\n"
		<< "Command >> '3' or 'bank'		>> Bank 'x' mode, without Sticky Keys.\n"
		<< "Command >> '4' or 'bank sticky'		>> Bank 'x' mode, with Sticky Keys (see FAQ).\n"
		<< "Command >> 'clear'			>> Clear command line.\n"
		<< "Command >> 'manual'			>> Prints the command list.\n"
		<< "Command >> 'faq'			>> Prints the FAQ.\n"
		<< "Command >> 'exit'			>> Close the program.\n"
		<< std::endl;
}
void PrintFAQ() {
	std::cout << "NOT YET IMPLEMENTED\n" << std::endl;
}

// Program Main
int main() {
	PrintDisclaimers();
	PrintCommands();
	
	bool isProgramRunning = true; // Controls the main program loop.
	while (isProgramRunning)
	{
		std::cout << "Please Input the mode you wish to activate..." << std::endl;	// Write the text letting the user know they can enter a command.
		std::string enteredCommand;													// Stores the users command.
		std::getline(std::cin, enteredCommand);										// Gets the users command.

		// Check what command was entered and run the appropriate function calls.
		if (enteredCommand == "exit")
		{
			std::cout << "Exit of the program initialised, clearing up and closing.\n" << std::endl;
			isProgramRunning = false;
		}
		else if (enteredCommand == "clear")
		{
			system("cls");	// BAD PRACTICE, LOOKING FOR AN ALTERNATIVE.
			PrintCommands();
		}
		else if (enteredCommand == "manual")
		{
			std::cout << "\n" << std::endl;
			PrintCommands();
		}
		else if (enteredCommand == "faq")
		{
			PrintFAQ();
		}
		else if (enteredCommand == "reset" || enteredCommand == "0") {
			// Reset the system settings to a base mode, this currently is hardcoded to use the developer's defaults. This will be changed and expanded later to allow users to save/load their own settings.
			SetMouseSpeed(10);
			SetMouseSettings(6, 10, true);		// Reactivates Enhanced Pointer Precision with the threshold values which normally get set my the OS, the SPI function doesn't automatically set these values on the activation of the setting.
			SetMouseKeySettings(0, 184, 3000);	// Jump values are entirely placeholder as MKs will be deactivated.
			SetStickKeySettings(0);
			std::cout << "MouseKeys have been turned off and the mouse settings have been reset.\n" << std::endl;
		}
		else if (enteredCommand == "drop" || enteredCommand == "1") {
			// Drop Mode.
			SetMouseSpeed(10);
			SetMouseSettings(0, 0, false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 184, 3000);
			SetStickKeySettings(0);
			std::cout << "MouseKey Mode has been set to Drop mode.\n" << std::endl;
		}
		else if (enteredCommand == "drop sticky" || enteredCommand == "2") {
			// Drop Mode, with Stick Key support.
			SetMouseSpeed(10);
			SetMouseSettings(0, 0, false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 184, 3000);
			SetStickKeySettings((SKF_AUDIBLEFEEDBACK | SKF_AVAILABLE | SKF_STICKYKEYSON | SKF_INDICATOR | SKF_TRISTATE));
			std::cout << "MouseKey Mode has been set to Drop mode, using Sticky Keys.\n" << std::endl;
		}
		else if (enteredCommand == "bank" || enteredCommand == "3") {
			// Bank (x) Mode.
			SetMouseSpeed(10);
			SetMouseSettings(0, 0, false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 358, 3000);
			SetStickKeySettings(0);
			std::cout << "MouseKey Mode has been set to Bank 'x' mode.\n" << std::endl;
		}
		else if (enteredCommand == "bank sticky" || enteredCommand == "4") {
			// Bank (x) Mode, with Stick Key support.
			SetMouseSpeed(10);
			SetMouseSettings(0, 0, false);
			SetMouseKeySettings((MKF_AVAILABLE | MKF_MOUSEKEYSON | MKF_INDICATOR | MKF_LEFTBUTTONSEL | MKF_MODIFIERS | MKF_REPLACENUMBERS), 358, 3000);
			SetStickKeySettings((SKF_AUDIBLEFEEDBACK | SKF_AVAILABLE | SKF_STICKYKEYSON | SKF_INDICATOR | SKF_TRISTATE));
			std::cout << "MouseKey Mode has been set to Bank 'x' mode, using Sticky Keys.\n" << std::endl;
		}
		else
		{
			std::cout << "Unknown input, pease try again.\n" << std::endl;
		}
	}
}