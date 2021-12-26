#ifndef _FILETASK_H
#define _FILETASK_H

#include "fileTask.cpp"

bool fileExist1(const string &filename);
void openAndCheck(ifstream &filevao, char* name);
void openAndWarning(ostream &filera, char* name);

#endif