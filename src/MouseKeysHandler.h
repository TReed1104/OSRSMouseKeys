#ifndef OSRSMOUSEKEYS_MOUSEKEYSHANDLER_H_
#define OSRSMOUSEKEYS_MOUSEKEYSHANDLER_H_

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

class MouseKeysHandler {
public:
	MouseKeysHandler();
	~MouseKeysHandler();

	MOUSEKEYS GetSettings(void);
	void SetSettings(const DWORD& flags, const DWORD& topSpeed, const DWORD& acceleration);

private:

};

#endif
