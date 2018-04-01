#include "MouseHandler.h"

MouseHandler::MouseHandler() {

}

MouseHandler::~MouseHandler() {

}

int MouseHandler::GetMousespeed(void) {
	// Creates an int to hold the data passed back by the Windows SPI API.
	int mouseSpeed = -1;

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, &mouseSpeed, 0);
	return mouseSpeed;
}
void MouseHandler::SetMousespeed(const int &newSpeed) {
	// Passes the new value to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, (LPVOID)newSpeed, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
void MouseHandler::GetMouseSettings(const int inputArray[]) {
	// Creates an array to hold the data passed back by the Windows SPI API.
	int mouseParams[3];

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETMOUSE, 0, mouseParams, 0);
	inputArray = mouseParams;
}
void MouseHandler::SetMouseSettings(const int& mouseThresholdX, const int& mouseThresholdY, const bool& enablePointerPrecisionState) {
	// Creates and fills an array with the new settings.
	int mouseParams[3];
	mouseParams[0] = mouseThresholdX;
	mouseParams[1] = mouseThresholdY;
	mouseParams[2] = (int)enablePointerPrecisionState;	// This sets the enhance pointer precision setting to off.

														// Passes the array to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSE, 0, mouseParams, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
