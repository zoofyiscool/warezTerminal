#include "functions.h"

void disneyMinigame() {
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
    std::cout << shellName << ": Estimated files to be deleted each " << ranStealTime << " second(s): " << ranStealAmt << std::endl;		std::cout << "Continue? enter for yes [y/n]: ";
    std::string confirmPwnDis;
    std::getline(std::cin, confirmPwnDis);
    if (confirmPwnDis == "y" || confirmPwnDis == "") {
    	std::cout << shellName << ": Stage 2 initiated.." << std::endl;
        for (int i = 0; i <= ranSteal; i+=ranStealAmt) {
        	std::cout << "Deleting movies and TV shows.. " << i << std::endl;
            sleep(ranStealTime);
        }
		std::cout << "Deleted: " << ranSteal << std::endl;
        showShellOutput("Disney PWNED, fck DRM!\n");
        main();
    }
    else {
   		showShellOutput("Maybe another time then.\n");
        main();
	}
}

void discordMinigame() {
	int getCaught;
	srand(time(0));
	getCaught = (rand() % 5 + 1);
	std::cout << "Spoof username: ";
	std::string spoofUser;
	std::getline(std::cin, spoofUser);
	if (spoofUser == userName) {
		showShellOutput("Your spoof username cannot be the same as your normal one!");
		discordMinigame();
	}
	std::cout << "Spoof username set: " << spoofUser << std::endl;
	if (getCaught == 3) {
		for (int i = 0; i <= 3; i+=1) {
			clrScr();
			std::cout << "Discord system logs: " << spoofUser << " is gathering user info.. " << i << "/20" << std::endl;
			sleep(1);
		}
		showShellOutput("Your real username and location has been revealed!");
		/* will add randomness to location prolly */
		std::cout << "Discord system logs: Intruder found, username: " << userName << " location: Brazil" << std::endl;
		/* will add more to this */
	   	main();	
	}
	for (int i = 0; i <= 20; i+=1) {
		clrScr();
		std::cout << "Discord system logs: " << spoofUser << " is gathering user info.. " << i << "/20" << std::endl;
		sleep(1);
	}
	main();
}
