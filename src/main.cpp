// Includes for the main program
#include <iostream>

// Include the custom classes
#include "MouseHandler.h"
#include "MouseKeysHandler.h"
#include "StickyKeysHandler.h"

// Const settings values
const int jumpOptionOne = 120;
const int jumpOptionTwo = 180;
const int jumpOptionThree = 270;
const int jumpOptionFour = 360;

const int jumpDrop = 120;
const int jumpBanking = 360;
const int defaultMouseSpeed = 10;
const int defaultMouseAcceleration[3] = { 6, 10, true };
const int inUseMouseSettings[3] = { 0, 0, false };
const int defaultMouseKeyFlags = 268435683;
const int defaultStickyKeyFlags = 227;

bool isRunning;								// Controls the main program loop.
MouseHandler* mouseHandler;					// Handles Mouse Settings
MouseKeysHandler* mouseKeyHandler;			// Handles Mouse Keys Settings
StickyKeysHandler* stickyKeyHandler;		// Handle Stick Keys Settings

// This Function cleans up the program memory use on exit
void CleanUp(void) {
	delete mouseHandler;
	delete mouseKeyHandler;
	delete stickyKeyHandler;
}
// Print the Program Disclaimer
void PrintDisclaimer(void) {

}
// Print the UI
void PrintUI(void) {

}

// Program main
int main() {
	// Initialise our handlers
	mouseHandler = new MouseHandler();
	mouseKeyHandler = new MouseKeysHandler();
	stickyKeyHandler = new StickyKeysHandler();

	// Check all our Handlers were created.
	if ((mouseHandler || mouseKeyHandler || stickyKeyHandler) == NULL) {
		// Any of the handlers failed to initialise, don't run the program.
		isRunning = false;
	}
	else {
		// All of our handlers initialised, lets run the program.
		isRunning = true;
	}

	// Print the program opening text
	PrintDisclaimer();
	PrintUI();

	// Main program loop
	while (isRunning) {
		std::cout << "Please Input the mode you wish to activate..." << std::endl;
		std::string enteredCommand;					// Stores the users command
		std::getline(std::cin, enteredCommand);		// Get the user entry

		if (enteredCommand == "exit" || enteredCommand == "quit") {
			std::cout << "Exiting Program, clearing up and closing.\n" << std::endl;
			CleanUp();
			isRunning = false;
		}
		else if (enteredCommand == "clear") {
			system("cls");
			PrintUI();
		}
		else if (enteredCommand == "0" || enteredCommand == "reset") {
			std::cout << "Reloading Default Values.\n" << std::endl;
			mouseHandler->LoadDefaults();
			mouseKeyHandler->LoadDefaults();
			stickyKeyHandler->LoadDefaults();
		}
		else if (enteredCommand == "1") {
			std::cout << "Active Mode - JUMP ONE\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionOne);
			stickyKeyHandler->SetSettings(0);
		}
		else if (enteredCommand == "2") {
			std::cout << "Active Mode - JUMP TWO\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionTwo);
			stickyKeyHandler->SetSettings(0);
		}
		else if (enteredCommand == "3") {
			std::cout << "Active Mode - JUMP THREE\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionThree);
			stickyKeyHandler->SetSettings(0);
		}
		else if (enteredCommand == "4") {
			std::cout << "Active Mode - JUMP FOUR\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionFour);
			stickyKeyHandler->SetSettings(0);
		}
		else if (enteredCommand == "1s") {
			std::cout << "Active Mode - JUMP ONE WITH STICKY KEYS\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionOne);
			stickyKeyHandler->SetSettings(defaultStickyKeyFlags);
		}
		else if (enteredCommand == "2s") {
			std::cout << "Active Mode - JUMP TWO WITH STICKY KEYS\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionTwo);
			stickyKeyHandler->SetSettings(defaultStickyKeyFlags);
		}
		else if (enteredCommand == "3s") {
			std::cout << "Active Mode - JUMP THREE WITH STICKY KEYS\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionThree);
			stickyKeyHandler->SetSettings(defaultStickyKeyFlags);
		}
		else if (enteredCommand == "4s") {
			std::cout << "Active Mode - JUMP FOUR WITH STICKY KEYS\n" << std::endl;
			mouseHandler->SetMousespeed(defaultMouseSpeed);
			mouseHandler->SetMouseAcceleration(inUseMouseSettings[0], inUseMouseSettings[1], inUseMouseSettings[2]);
			mouseKeyHandler->SetMouseKeys(defaultMouseKeyFlags, jumpOptionFour);
			stickyKeyHandler->SetSettings(defaultStickyKeyFlags);
		}
		else {
			std::cout << "Unknown input, pease try again.\n" << std::endl;
		}
	}
}
