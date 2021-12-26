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
    {
        filevao.open(argv[1], ios::in);
        mystring = string((istreambuf_iterator<char>(filevao)), istreambuf_iterator<char>());
        text2morse(mystring, filera);
        filevao.close();
    }
    filera.close();
}