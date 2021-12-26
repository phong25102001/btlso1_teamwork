#ifndef _FILETASK_H
#define _FILETASK_H

#include "fileTask.cpp"

bool fileExist1(const string& );
void openAndCheck(ifstream&, char*);
void openAndWarning(ostream&, char*);
string textFile2string(ifstream&);
#endif