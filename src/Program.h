#ifndef OSRSMOUSEKEYS_PROGRAM_H_
#define OSRSMOUSEKEYS_PROGRAM_H_

// Includes for the main program
#include <iostream>

// Include the custom classes
#include "MouseHandler.h"
#include "MouseKeysHandler.h"
#include "StickyKeysHandler.h"

class Program {
public:
	// Const settings values
	const int jumpOptionOne = 120;
	const int jumpOptionTwo = 180;
	const int jumpOptionThree = 270;
	const int jumpOptionFour = 360;
	const int defaultMouseSpeed = 10;
	const int defaultMouseAcceleration[3] = { 6, 10, true };
	const int inUseMouseSettings[3] = { 0, 0, false };
	const int defaultMouseKeyFlags = 268435683;
	const int defaultStickyKeyFlags = 227;

	// General Variables
	bool isRunning;								// Controls the main program loop.
	MouseHandler* mouseHandler;					// Handles Mouse Settings
	MouseKeysHandler* mouseKeyHandler;			// Handles Mouse Keys Settings
	StickyKeysHandler* stickyKeyHandler;		// Handle Stick Keys Settings

	// Constructors
	Program();
	~Program();

	// Functions
	void Run();
	void CleanUp(void);
	void PrintDisclaimer(void);
	void PrintUI(void);
	void PrintFAQ(void);
	void ModeController(const int& mouseSpeed, const int mouseAcceleration[], const int& mouseKeyFlags, const int& mouseKeyJumpSpeed, const int& stickyKeyFlags);

private:

};

#endif
