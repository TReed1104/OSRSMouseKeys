#include "MouseKeysHandler.h"

MouseKeysHandler::MouseKeysHandler() {

}

MouseKeysHandler::~MouseKeysHandler() {

}

MOUSEKEYS MouseKeysHandler::GetSettings(void) {
	// Creates an appropriate struct to hold the data passed back by the Windows SPI API.
	MOUSEKEYS currentSettings;
	currentSettings.cbSize = sizeof(MOUSEKEYS);
	currentSettings.dwReserved1 = 0;
	currentSettings.dwReserved2 = 0;

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETMOUSEKEYS, sizeof(MOUSEKEYS), &currentSettings, 0);
	return currentSettings;
}
void MouseKeysHandler::SetSettings(const DWORD & flags, const DWORD & topSpeed, const DWORD & acceleration) {
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
