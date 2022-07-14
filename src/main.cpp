// TODO: COLOURS
// TODO: MORE COMMANDS

#include "functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <unordered_set>

std::string envUsr = getenv("USER");
std::string homeDir = "/home/";
std::string configUsr = homeDir + envUsr + "/.config/warezUsername.txt";
std::string response;
std::string nobodyDir = homeDir + envUsr + "/.config/warezHELPMEPLEASE";
std::string appName = "warezTerminal";
std::string shellName = "theShell";
std::string userName = "nobody";
std::string password;
std::string appVersion = "0.1.1-alpha";
bool isStarted = false;
//bool isNobody = false;
bool isNotNobody = true;
bool nobodyPest = false;
bool isNobody = false;
bool wasNobody = false; /* incase they try again.. */
bool nobodyAllowed = false; /* alright... */
time_t now = time(0);
char* dt = ctime(&now);

void showShellOutput(std::string msg);
void showMessage(std::string msg);
void readUserName();
void clrScr();
void helpMsg();
void removeAll();
void shellOutput();
void prinRes();
void startUp();
void nonUserShell();
void verMsg();

int main() {
	if (isStarted == false) {
		clrScr();
		readUserName();
		std::cout << "You are currently in the 'non-user' mode of " << appName << std::endl;
		std::cout << "To create a user, simply type 'setup'" << std::endl;
		nonUserShell();
	}
	else if (isStarted == true) {
		if (isNobody == true) {
			if (nobodyPest == true) {
				std::cout << "Try running the 'whoami' command! :)" << std::endl;
				nobodyPest = false;
			}
		}
		shellOutput();
		std::getline(std::cin, response);
		prinRes();
	}
	// return 0;
}

void startUp() {
	std::ifstream nobodyForever(nobodyDir);
	if (nobodyForever) {
		isNobody = true;
		nobodyPest = true;
		passFailSafe();
		checkPass();
	   	main();	
	}
	else {
		if (userName == "nobody") { /* thought this would be funny lol */
			if (wasNobody == true) {
				std::cout << "no way u done it again lol.." << std::endl;
				std::cout << "mAyBe TrY aGaIn?!" << std::endl;
				nobodyAllowed = true;
				wasNobody = false;
				nonUserShell();
			}
			if (nobodyAllowed == true) {
				std::cout << "fine, youve beaten me.. you can have it." << std::endl;
				std::cout << "you will have this forever. open application again and login.." << std::endl;
				std::ofstream nobodyForever(nobodyDir);
				nobodyForever << "why would you do this, i thought i was nobody, not you!!";
				nobodyForever.close();
				nobodyAllowed = false;
				exit(0);
			}
			if (isNotNobody == true) {
				wasNobody = true;
				std::cout << "Why?.. No lol.. Go back and fix it. :) " << std::endl;
				std::cout << "ur getting dropped into the non-user shell again.." << std::endl;
				std::cout << "type 'setup'" << std::endl;
			   	isNotNobody = false;	
				nonUserShell();
			}
		}
	}
	if (!nobodyForever) {
    	std::cout << appName << " " << appVersion << std::endl;
		passFailSafe();
		checkPass();
		std::cout << userName << " logged in at: " << dt << std::endl;
    	std::cout << "Try typing 'help'!\n" << std::endl;
		shellOutput();
		std::getline(std::cin, response);
		prinRes();
	}
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
		showShellOutput("Exit command recieved, quitting.");
		exit(0);
	}
    else if (response == "reset") {
		checkPass();
		removeAll();
		showShellOutput("Deleted saved configs, quitting");
		exit(0);
	}
	else if (response == "pwnDisney();") {
		disneyMinigame();
	}
	else if (response == "license") {
		showMessage("This program comes with ABSOLUTELY NO WARRANTY");
		std::cout << "This is free software, and you are welcome to redistribute it under certain conditions.\n" << 
		"For more information see the GNU General Public License 3 (or later)" << std::endl;
		main();
	}
	else if (response == "whoami") {
		if (userName == "nobody") {
			showMessage("You will never be nobody, you made a mistake typing this command :))");
			userName = "NEVER";
			std::cout << "ur screwed loll.." << std::endl;
			removeAll();
			main();
		}
		else {
			std::cout << userName << std::endl;
			main();
		}
	}
	else if (response == "version") {
		verMsg();
		main();
	}
	else if (response == "discordmini") {
		showMessage("This minigame is still in development. Lacking features.");
		discordMinigame();
	}
	else {
        std::cout << shellName << ": command not found: " << response << std::endl;;
        main();
	}
}

void clrScr() {
	system("clear");
}

void helpMsg() {
    showMessage("All commands listed below are built-in\n");
	showMessage("help - prints this message");
	showMessage("reset - deletes config file");
	showMessage("exit - exits this Application");
	showMessage("clear - clears the screen");
	showMessage("pwnDisney(); - hacks disney (not really)");
	showMessage("license - prints the license of this Application");
	showMessage("whoami - prints the name of the current user");
	showMessage("version - prints the version of this Application");
}

void nonUserShell() {
	removeAll();
	shellOutput();
	std::getline(std::cin, response);
	if (response == "setup") {
        std::cout << "New username: ";
		std::getline(std::cin, userName);
		std::cout << "New password: ";
		std::getline(std::cin, password);
		std::ofstream configUsrFile(configUsr);
		configUsrFile << userName;
		configUsrFile.close();
		accPass();
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

void removeAll() {
	const char* cfgPassDel = passFile.c_str();
	const char* cfgUsrDel = configUsr.c_str();
	const char* nobodyForeverDel = nobodyDir.c_str();
	std::ifstream configPassFileR(passFile);
	std::ifstream configUsrFileR(configUsr);
	std::ifstream nobodyForever(nobodyDir);
	if (configPassFileR) {
		std::remove(cfgPassDel);
	}
	if (configUsrFileR) {
		std::remove(cfgUsrDel);
	}
	if (nobodyForever) {
		std::remove(nobodyForeverDel);
	}

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

void showMessage(std::string msg) {
	std::cout << msg << std::endl;
}

void showShellOutput(std::string msg) {
	std::cout << shellName << ": " << msg << std::endl;
}

void verMsg() {
	showMessage(appVersion);
}
