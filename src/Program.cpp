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
	std::cout
		<< "Teebu's Mouse Key control panel\n"
		<< "A client for the quick setup of your Operating Systems Mouse Keys.\n\n"

		<< "DISCLAIMER:\n"
		<< "This project is an Open-Source client for the quick and easy toggling between the different\n"
		<< "mouse key modes commonly used for Old School Runescape.\n"
		<< "This program sets the Operating system's mouse key settings directly and therefore does not\n"
		<< "break the rules set out by Jagex.\n"
		<< std::endl;
}
void Program::PrintUI(void) {
	// Draw the UI.
	std::cout
		<< "COMMANDS:\n"
		<< "Command >> '0'		>> Load Defaults saved on program launch\n"
		<< "Command >> '1'		>> Jump 1 op distance (Use)\n"
		<< "Command >> '2'		>> Jump 2 op distance (Drop)\n"
		<< "Command >> '3'		>> Jump 3 op distance\n"
		<< "Command >> '4'		>> Jump 4 op distance (Bank X)\n"
		<< "Command >> '1s'		>> Jump 1 op distance (Use) with Sticky Keys enabled\n"
		<< "Command >> '2s'		>> Jump 2 op distance (Drop) with Sticky Keys enabled\n"
		<< "Command >> '3s'		>> Jump 3 op distance with Sticky Keys enabled\n"
		<< "Command >> '4s'		>> Jump 4 op distance (Bank X) with Sticky Keys enabled\n"
		<< "Command >> 'reset'	>> Load Defaults saved on program launch\n"
		<< "Command >> 'clear'	>> Clear the console\n"
		<< "Command >> 'manual'	>> Print this menu\n"
		<< "Command >> 'faq'	>> Print the FAQ\n"
		<< "Command >> 'exit'	>> Close the program\n"
		<< std::endl;
}
void Program::PrintFAQ(void) {
	std::cout << "NOT YET IMPLEMENTED\n" << std::endl;
}
void Program::ModeController(const int& mouseSpeed, const int mouseAcceleration[], const int& mouseKeyFlags, const int& mouseKeyJumpSpeed, const int& stickyKeyFlags) {
	mouseHandler->SetMousespeed(mouseSpeed);
	mouseHandler->SetMouseAcceleration(mouseAcceleration[0], mouseAcceleration[1], mouseAcceleration[2]);
	mouseKeyHandler->SetMouseKeys(mouseKeyFlags, mouseKeyJumpSpeed);
	stickyKeyHandler->SetSettings(stickyKeyFlags);
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
		std::cout << "\nPlease Input the mode you wish to activate..." << std::endl;
		std::string enteredCommand;					// Stores the users command
		std::getline(std::cin, enteredCommand);		// Get the user entry

		if (enteredCommand == "exit" || enteredCommand == "quit") {
			isRunning = false;
		}
		else if (enteredCommand == "clear") {
			system("cls");
			PrintUI();
		}
		else if (enteredCommand == "manual") {
			PrintUI();
		}
		else if (enteredCommand == "faq") {
			PrintFAQ();
		}
		else if (enteredCommand == "0" || enteredCommand == "reset") {
			std::cout << "Reloading Default Values." << std::endl;
			mouseHandler->LoadDefaults();
			mouseKeyHandler->LoadDefaults();
			stickyKeyHandler->LoadDefaults();
		}
		else if (enteredCommand == "1") {
			std::cout << "Active Mode - JUMP ONE" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionOne, 0);
		}
		else if (enteredCommand == "2") {
			std::cout << "Active Mode - JUMP TWO" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionTwo, 0);
		}
		else if (enteredCommand == "3") {
			std::cout << "Active Mode - JUMP THREE" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionThree, 0);
		}
		else if (enteredCommand == "4") {
			std::cout << "Active Mode - JUMP FOUR" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionFour, 0);
		}
		else if (enteredCommand == "1s") {
			std::cout << "Active Mode - JUMP ONE WITH STICKY KEYS" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionOne, defaultStickyKeyFlags);
		}
		else if (enteredCommand == "2s") {
			std::cout << "Active Mode - JUMP TWO WITH STICKY KEYS" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionTwo, defaultStickyKeyFlags);
		}
		else if (enteredCommand == "3s") {
			std::cout << "Active Mode - JUMP THREE WITH STICKY KEYS" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionThree, defaultStickyKeyFlags);
		}
		else if (enteredCommand == "4s") {
			std::cout << "Active Mode - JUMP FOUR WITH STICKY KEYS" << std::endl;
			this->ModeController(defaultMouseSpeed, inUseMouseSettings, defaultMouseKeyFlags, jumpOptionFour, defaultStickyKeyFlags);
		}
		else {
			std::cout << "Unknown input, pease try again." << std::endl;
		}
	}
}
