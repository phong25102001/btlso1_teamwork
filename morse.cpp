#include <iostream>
#include <fstream>
#include <string>
#include "fileTask.h"
#include "morseCode.h"

using namespace std;

int main(int argc, char *argv[])
{
    char temp[1];
    string mystring;
    ofstream filera;
    ifstream filevao;

    openAndCheck(filevao, argv[1]);
    mystring = textFile2string(filevao);
    cout << int(checkIfMorse(mystring)) << endl;
    filevao.close();

    openAndWarning(filera, argv[2]);
    morse2text(mystring, filera);
    filera.close();
}