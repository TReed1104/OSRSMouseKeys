#include "StickyKeysHandler.h"

StickyKeysHandler::StickyKeysHandler() {

}

StickyKeysHandler::~StickyKeysHandler() {

}

STICKYKEYS StickyKeysHandler::GetSettings() {
	// Creates an appropriate struct to hold the data passed back by the Windows SPI API.
	STICKYKEYS currentSettings;
	currentSettings.cbSize = sizeof(STICKYKEYS);

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &currentSettings, 0);
	return currentSettings;
}

void StickyKeysHandler::SetSettings(const DWORD & flags) {
	// Creates and fills an appropriate struct with the new settings.
	STICKYKEYS newSettings;
	newSettings.cbSize = sizeof(STICKYKEYS);
	newSettings.dwFlags = flags;

	// Passes the struct to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), (LPVOID)&newSettings, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
