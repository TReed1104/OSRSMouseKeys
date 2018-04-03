#include "MouseHandler.h"

MouseHandler::MouseHandler() {
	this->SaveDefaults();
}

MouseHandler::~MouseHandler() {
	this->LoadDefaults();
}

void MouseHandler::SaveDefaults(void) {
	defaultSpeed = this->GetMousespeed();
}
void MouseHandler::LoadDefaults(void) {
	std::cout << "Reloading the Users Default Mouse Settings" << std::endl;
	this->SetMousespeed(defaultSpeed);
	this->SetMouseAcceleration(defaultMouseAcceleration[0], defaultMouseAcceleration[1], defaultMouseAcceleration[2]);
}
int MouseHandler::GetMousespeed(void) {
	// Creates an int to hold the data passed back by the Windows SPI API.
	int mouseSpeed = -1;

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETMOUSESPEED, 0, &mouseSpeed, 0);
	return mouseSpeed;
}
void MouseHandler::SetMousespeed(const int &newSpeed) {
	// Passes the new value to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSESPEED, 0, (LPVOID)newSpeed, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
void MouseHandler::GetMouseAcceleration(const int outputArray[]) {
	// [0] mouseThresholdX
	// [1] mouseThresholdY
	// [2] enablePointerPrecisionState

	// Passes the struct to the API, which then fills the struct with the appropriate current data.
	SystemParametersInfo(SPI_GETMOUSE, 0, &outputArray, 0);
}
void MouseHandler::SetMouseAcceleration(const int& mouseThresholdX, const int& mouseThresholdY, const int& enablePointerPrecisionState) {
	// Creates and fills an array with the new settings.
	int mouseParams[3];
	mouseParams[0] = mouseThresholdX;
	mouseParams[1] = mouseThresholdY;
	mouseParams[2] = enablePointerPrecisionState;	// This sets the enhance pointer precision setting to off.

	// Passes the array to the Windows SPI API, applying the changes.
	SystemParametersInfo(SPI_SETMOUSE, 0, &mouseParams, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE);
}
