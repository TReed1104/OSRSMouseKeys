#include "StickyKeysHandler.h"

StickyKeysHandler::StickyKeysHandler() {
	this->SaveDefaults();
}
StickyKeysHandler::~StickyKeysHandler() {
	this->LoadDefaults();
}

void StickyKeysHandler::SaveDefaults(void) {
	defaultStickKeyFlags = this->GetSettings().dwFlags;
}
void StickyKeysHandler::LoadDefaults(void) {
	std::cout << "Reloading the Users Default Sticky Key Settings" << std::endl;
	this->SetSettings(defaultStickKeyFlags);
}
STICKYKEYS StickyKeysHandler::GetSettings() {
	// Creates an appropriate struct to hold the data passed back by the Windows SPI API.
	STICKYKEYS currentSettings;
	currentSettings.cbSize = sizeof(STICKYKEYS);

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &currentSettings, 0);
	return currentSettings;
}
void StickyKeysHandler::SetSettings(const int& flags) {
	// Creates and fills an appropriate struct with the new settings.
	STICKYKEYS newSettings;
	newSettings.cbSize = sizeof(STICKYKEYS);
	newSettings.dwFlags = (DWORD)flags;

	// Passes the struct to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), (LPVOID)&newSettings, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
