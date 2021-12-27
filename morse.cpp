#include <fstream>          // mở và đóng file
#include <string>           // khai báo chuỗi và chuyển đổi chuỗi.
#include "fileTask.h"       // các hàm xử lí file đọc file thành string và hiện thị lỗi nếu có
#include "morseCode.h"      // các hàm mã hóa và giải mã morse <-> text, hiện thị lỗi hoặc lưu ý nếu có

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
        /* Trường hợp file vào là file text.
        *  cần xử lí riêng vì xử lí file morse phải thêm dấu cách mà text thì không.
        */

        filevao.open(argv[1], ios::in);
        mystring = string((istreambuf_iterator<char>(filevao)), istreambuf_iterator<char>()); // chuyển file dữ liệu thành string.
        filevao.close();

        text2morse(mystring, filera);
    }

    filera.close();
    return 0;
}