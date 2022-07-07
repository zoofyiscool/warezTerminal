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
