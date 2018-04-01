#ifndef OSRSMOUSEKEYS_MOUSEHANDLER_H_
#define OSRSMOUSEKEYS_MOUSEHANDLER_H_

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

class MouseHandler {
public:
	MouseHandler();
	~MouseHandler();

	int GetMousespeed(void);
	void SetMousespeed(const int& newSpeed);

	void GetMouseSettings(const int inputArray[]);
	void SetMouseSettings(const int& mouseThresholdX, const int& mouseThresholdY, const bool& enablePointerPrecisionState);

private:

};

#endif
