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
    std::cout << shellName << ": Estimated files to be deleted each " << ranStealTime << " second(s): " << ranStealAmt << std::endl;    std::cout << "Continue? enter for yes [y/n]: ";
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
