#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include "unistd.h"

extern std::string shellName;
extern std::string userName;
extern std::string passFile;
extern std::string envUsr;
extern std::string homeDir;
extern std::string appName;
extern std::string password;
extern std::string msg;

int main();
void accPass();
void passFailSafe();
void clrScr();
void nonUserShell();
void removeAll();
void checkPass();
void disneyMinigame();
void showShellOutput(std::string msg);
void discordMinigame();

#endif
