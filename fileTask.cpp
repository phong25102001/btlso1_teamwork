#ifndef _FILETASK_CPP
#define _FILETASK_CPP

#include <iostream>
#include <fstream>
using namespace std;

bool fileExist1(const string &filename)
{
    // Kiểm tra file có tên <filename> có tồn tại hay không
    // Nếu tồn tại => trả về true
    ifstream f(filename.c_str());
    return f.good();
}

void openAndCheck(ifstream &filevao, char* name)
{
    try
    {
        // Error: FILENAME could not be opened
        filevao.open(name, ios::in);
        if (filevao.fail())
            throw "could not be opened";
    }
    catch (const char* &err)
    {
        cerr<< "Error: "<< name<< " "<< err<< endl;
        exit(1);
    }
}

void openAndWarning(ofstream &filera, char* name)
{
    if (fileExist1(name)) 
    {
        cout << "Warning: " << name << " already exists. Do you wish to overwrite (y,n)? ";
        char yesNo;
        cin >> yesNo;
        if (yesNo != 'y')
            exit(1); 
    }
    filera.open(name, ios::out | ios::trunc);
}


#endif
