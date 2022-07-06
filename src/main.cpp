// TODO: PASSWORD SYSTEM WITH ENCRYPTION
// TODO: MORE COMMANDS

#include "functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>

std::string envUsr = getenv("USER");
std::string homeDir = "/home/";
std::string fileDir = "/.config/warezUsername.txt";
std::string configUsr = homeDir + envUsr + fileDir;
std::string response;
std::string appName = "warezTerm";
std::string shellName = "theShell";
std::string userName = "nobody";
bool isStarted = false;
time_t now = time(0);
char* dt = ctime(&now);

void readUserName();
void clrScr();
void helpMsg();
void shellOutput();
void prinRes();
void startUp();
void nonUserShell();

int main() {
	if (isStarted == false) {
		clrScr();
		readUserName();
		std::cout << "You are currently in the 'non-user' mode of " << appName << std::endl;
		std::cout << "To create a user, simply type 'setup'" << std::endl;
		nonUserShell();
	}
	else if (isStarted == true) {
		shellOutput();
		std::getline(std::cin, response);
		prinRes();
	}
	// return 0;
}

void startUp() {
    std::cout << appName << " 0.1" << std::endl;
	//time_t now = time(0);
	//char* dt = ctime(&now);
	std::cout << userName << " logged in at: " << dt << std::endl;
    std::cout << "Try typing 'help'!\n" << std::endl;
	shellOutput();
	std::getline(std::cin, response);
	prinRes();
}

void prinRes() {
	if (response == "help") {
		helpMsg();
		//std::cout << "\n" << std::endl;
        main();
	}
	else if (response == "clear") {
        clrScr();
        main();
	}
	else if (response == "exit") {
		std::cout << shellName << ": Exit command recieved, quitting." << std::endl;
		exit(0);
	}
    else if (response == "reset") {
		const char* cfgUsrDel = configUsr.c_str();
		std::remove(cfgUsrDel);
		std::cout << shellName << ": Deleted saved configs, quitting." << std::endl;
		exit(0);
	}
	else if (response == "pwnDisney();") {
		int ranSteal, ranStealTime, ranStealAmt;
		srand(time(0));
		ranSteal = (rand() % 3500 + 100);
		ranStealTime = (rand() % 3 + 1);
		ranStealAmt = (rand() % 3 + 123);
		for (int i = 0; i <= 100; i+=10) {
			std::cout << shellName << ": Hacking servers.. " << i << "%" << std::endl;
			sleep(1);
		}
		std::cout << shellName << ": Amount of movies and TV shows to delete: " << ranSteal << std::endl;
		std::cout << shellName << ": Estimated wait time: " << ranStealTime << std::endl;
		std::cout << shellName << ": Estimated files getting deleted each " << ranStealTime << " second(s): " << ranStealAmt << std::endl;
		std::cout << "Continue? [y/n]: ";
		std::string confirmPwnDis;
		std::getline(std::cin, confirmPwnDis);
		if (confirmPwnDis == "y") {
			std::cout << shellName << ": Stage 2 initiated.." << std::endl;
			for (int i = 0; i <= ranSteal; i+=ranStealAmt) {
				std::cout << shellName << ": Deleting movies and TV shows.. " << i << std::endl;
				sleep(ranStealTime);
			}
			std::cout << shellName << ": Disney PWNED, fck DRM!\n" << std::endl;
			main();
		}
		else {
			std::cout << shellName << ": Maybe another time then.\n" << std::endl;
			main();
		}
	}
	else if (response == "license") {
		std::cout << "This program comes with ABSOLUTELY NO WARRANTY" << std::endl;
		std::cout << "This is free software, and you are welcome to redistribute it under certain conditions.\n" << 
		"For more information see the GNU General Public License 3 (or later)" << std::endl;
		main();
	}
	else {
        std::cout << shellName << ": command not found: " << response << std::endl;
        main();
	}
}

void clrScr() {
	system("clear");
}

void helpMsg() {
        std::cout << "All commands listed below are built-in\n" << std::endl;
		std::cout << "help - prints this message" << std::endl;
		std::cout << "reset - deletes config file" << std::endl;
		std::cout << "exit - exits "<< appName << std::endl;
		std::cout << "clear - clears the screen" << std::endl;
		std::cout << "pwnDisney(); - hacks disney (not really)" << std::endl;
		std::cout << "license - prints the license of " << appName << std::endl;
}

void nonUserShell() {
	shellOutput();
	std::getline(std::cin, response);
	if (response == "setup") {
        std::cout << "New username: ";
		std::getline(std::cin, userName);
		std::ofstream configUsrFile(configUsr);
		configUsrFile << userName;
		configUsrFile.close();
		isStarted = true;
		std::cout << shellName << ": User created!, starting " << shellName << ".. " << std::endl;
		sleep(3);
		clrScr();
		startUp();
	}
	else if (response == "exit") {
		std::cout << shellName << ": Exit command recieved, quitting." << std::endl;
		exit(0);
	}
	else {
		std::cout << shellName << ": command not found: " << response << std::endl;
		nonUserShell();
	}
}

void shellOutput() {
	std::cout << userName << "@" << shellName << "> ";
}

void readUserName() {
	std::ifstream configUsrFileR(configUsr);
	if (configUsrFileR) {
		while (getline (configUsrFileR, userName)){
			std::cout << shellName << ": Read from config file, starting " << shellName << ".\n" << std::endl;
			// isStarted = true;
		}
		isStarted = true;
		startUp();
	}
	else {
		std::cout << "Welcome to " << appName << std::endl;
		std::cout << shellName << ": Config file not found, dropping in non-user shell.\n" << std::endl;
	}
	configUsrFileR.close();
}
