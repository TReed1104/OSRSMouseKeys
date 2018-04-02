#ifndef OSRSMOUSEKEYS_STICKYKEYSHANDLER_H_
#define OSRSMOUSEKEYS_STICKYKEYSHANDLER_H_

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>

class StickyKeysHandler {
public:
	// Default values, these are set on program load
	int defaultStickKeyFlags;

	// Constructors
	StickyKeysHandler();
	~StickyKeysHandler();

	// Functions
	void LoadDefaults(void);
	STICKYKEYS GetSettings();
	void SetSettings(const int& flags);

private:
	// Functions
	void SaveDefaults(void);

};

#endif
