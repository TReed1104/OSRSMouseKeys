#ifndef OSRSMOUSEKEYS_STICKYKEYSHANDLER_H_
#define OSRSMOUSEKEYS_STICKYKEYSHANDLER_H_

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

class StickyKeysHandler {
public:
	StickyKeysHandler();
	~StickyKeysHandler();

	STICKYKEYS GetSettings();
	void SetSettings(const DWORD &flags);

private:

};

#endif
