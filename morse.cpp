#include <iostream>
#include <fstream>
#include <string>
#include "fileTask.h"
#include "morseCode.h"

using namespace std;

int main(int argc, char *argv[])
{
    string mystring;
    ofstream filera;
    ifstream filevao;

    openAndCheck(filevao, argv[1]);
    mystring = textFile2string(filevao); 
    filevao.close();

    openAndWarning(filera, argv[2]);
    if (checkIfMorse(mystring))
        morse2text(mystring, filera);
    else 
        text2morse(mystring, filera);
    
    filera.close();
}