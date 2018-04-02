#ifndef OSRSMOUSEKEYS_MOUSEKEYSHANDLER_H_
#define OSRSMOUSEKEYS_MOUSEKEYSHANDLER_H_

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

class MouseKeysHandler {
public:
	// Default values, these are set on program load
	int defaultJumpSpeed;
	int defaultFlags;

	// Constructors
	MouseKeysHandler();
	~MouseKeysHandler();

	// Functions
	void LoadDefaults(void);
	void GetJumpSpeed(const int& outputFlags, const int& outputJumpSpeed);
	void SetMouseKeys(const int& flags, const int& jumpSpeed);

private:
	// Functions
	void SaveDefaults(void);

};

#endif
