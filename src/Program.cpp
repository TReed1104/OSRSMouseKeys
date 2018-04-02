#include "Program.h"

Program::Program() {
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
}
Program::~Program() {
	this->CleanUp();
}

void Program::PrintDisclaimer(void) {

}
void Program::PrintUI(void) {

}
void Program::CleanUp(void) {
	delete mouseHandler;
	delete mouseKeyHandler;
	delete stickyKeyHandler;
}
void Program::Run() {
	// Print the program opening text
	PrintDisclaimer();
	PrintUI();

	// Main program loop
	while (isRunning) {
		std::cout << "Please Input the mode you wish to activate..." << std::endl;
		std::string enteredCommand;					// Stores the users command
		std::getline(std::cin, enteredCommand);		// Get the user entry

		if (enteredCommand == "exit" || enteredCommand == "quit") {
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
