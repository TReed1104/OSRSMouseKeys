#include "MouseKeysHandler.h"

MouseKeysHandler::MouseKeysHandler() {
	this->SaveDefaults();
}
MouseKeysHandler::~MouseKeysHandler() {
	this->LoadDefaults();
}

void MouseKeysHandler::SaveDefaults(void) {
	this->GetJumpSpeed(defaultFlags, defaultJumpSpeed);
}
void MouseKeysHandler::LoadDefaults(void) {
	std::cout << "Reloading the Users Default Mouse Key Settings" << std::endl;
	this->SetMouseKeys(defaultFlags, defaultJumpSpeed);
}
void MouseKeysHandler::GetJumpSpeed(const int& outputFlags, const int& outputJumpSpeed) {
	// Creates an appropriate struct to hold the data passed back by the Windows SPI API.
	MOUSEKEYS currentSettings;
	currentSettings.cbSize = sizeof(MOUSEKEYS);
	currentSettings.dwReserved1 = 0;
	currentSettings.dwReserved2 = 0;

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETMOUSEKEYS, sizeof(MOUSEKEYS), &currentSettings, 0);

	// Set the output
	defaultFlags = currentSettings.dwFlags;
	defaultJumpSpeed = currentSettings.iMaxSpeed;
}
void MouseKeysHandler::SetMouseKeys(const int& flags, const int& jumpSpeed) {
	// Creates and fills an appropriate struct with the new settings.
	MOUSEKEYS newSettings;
	newSettings.cbSize = sizeof(MOUSEKEYS);
	newSettings.dwFlags = (DWORD)flags;
	newSettings.iMaxSpeed = (DWORD)jumpSpeed;
	newSettings.iTimeToMaxSpeed = (DWORD)3000;
	newSettings.iCtrlSpeed = 0;
	newSettings.dwReserved1 = 0;
	newSettings.dwReserved2 = 0;

	// Passes the struct to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSEKEYS, sizeof(MOUSEKEYS), (LPVOID)&newSettings, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
