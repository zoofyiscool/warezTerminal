#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>

extern std::string userName;
extern std::string passFile;
extern std::string envUsr;
extern std::string homeDir;
extern std::string appName;
extern std::string password;
void accPass();
void passFailSafe();
void nonUserShell();
void removeAll();

#endif
