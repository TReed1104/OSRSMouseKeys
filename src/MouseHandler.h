#ifndef OSRSMOUSEKEYS_MOUSEHANDLER_H_
#define OSRSMOUSEKEYS_MOUSEHANDLER_H_

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

class MouseHandler {
public:
	// Default values, these are set on program load
	int defaultSpeed;
	int defaultMouseAcceleration[3] = { 6, 10, true };

	// Constructors
	MouseHandler();
	~MouseHandler();

	// Functions
	void LoadDefaults(void);
	int GetMousespeed(void);
	void SetMousespeed(const int& newSpeed);
	void GetMouseAcceleration(const int outputArray[]);
	void SetMouseAcceleration(const int& mouseThresholdX, const int& mouseThresholdY, const int& enablePointerPrecisionState);

private:
	// Functions
	void SaveDefaults(void);

};

#endif
