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
    
    // xử lí lỗi Error: FILENAME could not be opened
    // filevao: biến ifstream thử mở file vào
    // name: tên file vào
    try
    {
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
    // xử lí file ra nếu đã tồn tại báo Warning: FILENAME already exists. Do you wish to overwrite (y,n)?
    // filera: biến ofstream xác định filera nếu người dùng đồng ý ghi đè
    // name: tên file đầu ra sau khi giải mã hoặc mã hóa morse code
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
