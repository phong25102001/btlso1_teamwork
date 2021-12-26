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
    // filevao.open("1.txt", ios::in);
    mystring = string((istreambuf_iterator<char>(filevao)), istreambuf_iterator<char>());
    cout << int(checkIfMorse(mystring)) << endl;
    filevao.close();

    openAndWarning(filera, argv[2]);
    // filera.open("2.txt", ios::out | ios::trunc);
    morse2text(mystring, filera);
    filera.close();
}