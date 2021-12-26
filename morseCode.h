#ifndef _MORSECODE_H
#define _MORSECODE_H

#include "morseCode.cpp"

bool checkIfMorse(const string&);
void morse2text(string&, ofstream&);
void text2morse(string&, ofstream&);

#endif