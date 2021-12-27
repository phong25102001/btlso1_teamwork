#ifndef _FILETASK_CPP
#define _FILETASK_CPP

#include <iostream>     // in lỗi hoặc Warning hoặc hướng dẫn sử dụng.
#include <fstream>      // khai báo và xử lí các tác vụ liên quan đến file.
#include <string>       // khai báo và xử lí chuỗi
using namespace std;

bool fileExist(const string &filename)
{
    /* Kiểm tra file có tên <filename> có tồn tại hay không.
    *
    *  Input: <filename> là tên file cần kiểm tra.
    *  Output: true nếu file có tên <filename> đã tồn tại.
    *          false nếu file có tên <filename> chưa có.
    * 
    */

    ifstream f(filename.c_str());
    return f.good();
}

void openAndCheck(ifstream &filevao, char* name)
{
    /* mở file và xử lí lỗi Error: FILENAME could not be opened nếu có
    * 
    *  Input: <filevao> biến ifstream để thử mở file vào.
    *         <name>: tên file vào cần mở và kiểm tra có mở được không.
    *  Output: In lỗi ra cmd và thoát khỏi chương trình nếu không mở được <filevao>
    *  
    */

    try
    {
        filevao.open(name, ios::in);
        if (filevao.fail())                                              // mở file thất bại => phát sinh lỗi
            throw "could not be opened";
    }
    catch (const char* &err)                                             // xử lí lỗi được phát sinh
    {
        cerr<< "Error: "<< name<< " "<< err<< endl;
        exit(1);
    }
}

void openAndWarning(ofstream &filera, char* name)
{
    /* xử lí file ra nếu đã tồn tại báo Warning: FILENAME already exists. Do you wish to overwrite (y,n)?
    *
    * Input: <filera>: biến ofstream xác định file đầu ra nếu người dùng đồng ý ghi đè.
    *        <name>: tên file đầu ra sau khi giải mã hoặc mã hóa morse code.
    * Output: nếu <filera> đã tồn tại thì hiện lưu ý và xử lí nếu người dùng cho phép hoặc không cho phép ghi đè
    * 
    */

    if (fileExist(name)) 
    {
        cout << "Warning: " << name << " already exists. Do you wish to overwrite (y,n)? ";
        char yesNo;
        cin >> yesNo;

        if (yesNo != 'y')
            exit(1);                                                     // thoát nếu người dùng không muốn ghi đè
    }
    filera.open(name, ios::out | ios::trunc);                            // mở file ở chế độ output và trunc(ghi đè, không nối thêm vào file cũ)
}

string textFile2string(ifstream& filevao)
{
    /* chuyển toàn bộ dữ liệu của filevao thành string (có xử lí thêm để tiện cho việc chuyển file morse -> text)
    *  
    *  Input: <filevao> biến ifstream chỉ thị file vào cần chuyển sang dạng string
    *  Output: chuỗi được chuyển thành string từ <filevao>
    * 
    */

    // chuyển đổi chuỗi về dạng string:
    string temp = string((istreambuf_iterator<char>(filevao)), istreambuf_iterator<char>());
    
    long length = temp.length();

    for(long i = 0; i <= length; i++)                                    // duyệt chuỗi
    {
        if(temp[i]=='\n' || temp[i]=='\0')
        {    
            temp.insert(i, " ");                                         // thêm các dấu cách để tiện xử lí hàm morse2text
            length++;
            i++;
        }
    }
    return temp;
}

#endif
