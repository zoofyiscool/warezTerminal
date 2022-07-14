#include "functions.h"

std::string passFile = homeDir + envUsr + "/.config/warezPass.txt";

void accPass() {
	std::ofstream configPassFile(passFile);
	configPassFile << password;
	configPassFile.close();
}

void passFailSafe() {
	std::ifstream configPassFileR(passFile);

	if (configPassFileR) {
		std::cout << "Password file exists" << std::endl;
		configPassFileR.close();
	}
	else {
		std::cout << "Critical error: Password file doesn't exist" << std::endl;
		configPassFileR.close();
		removeAll();
		userName = "nobody";
		std::cout << "All config files removed, dropping into non-user shell\n" <<
		"so you can setup a new user again.\n" << "Type 'setup'" << std::endl;
		nonUserShell();
		exit(0);
	}
}

void checkPass() {
	std::cout << "Enter your password: ";
	std::getline(std::cin, password);
	std::ifstream passFileR(passFile);
	std::string linePass;
	std::unordered_set<std::string> res;
	while (passFileR >> linePass) {
		res.insert(linePass);
	}
	do {
		if (res.find(password) != res.end()) {
			clrScr();
			std::cout << shellName << ": Password correct" << std::endl;
			break;
		}
		else {
			std::cout << shellName << ": Password incorrect" << std::endl;
			checkPass();
		}
	} while(true);
}
