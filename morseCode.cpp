#ifndef _MORSECODE_CPP
#define _MORSECODE_CPP

#define ALL 70
#include <iostream>     // thông báo lỗi hoặc warning
#include <fstream>      // đọc hoặc ghi file
#include <string>       // xử lí chuỗi và khai báo bộ dữ liệu mã hóa <-> giải mã
using namespace std;

//-------------------Định nghĩa khối dữ liệu text và morse phục vụ mã hóa và giải mã---------------------//

const string text[ALL]=
{
  "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
  
  "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
  
  "1","2","3","4","5","6","7","8","9","0"," ","#",".","?","-",",",":"
};

const string morse[ALL]=
{
  ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  
    ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  
   ".----", "..---", "...--","....-", ".....", "-....", "--...", "---..", "----.", "-----",
   
   "/","........",".-.-.-","..--..","-....-","--..--","---..."
};

//-------------------------------------------------------------------------------------------------------//

bool checkIfMorse(const string& textInFile)
{

    /* Kiểm tra các kí tự trong chuỗi <textInFile> đọc từ file đầu vào có phải file morse không.
    * 
    *  Input: <textInFile> là dữ liệu của file sau khi đã chuyển thành dạng string.
    *  Output: true nếu <textInFile> là dữ liệu của file morse.
    *          false nếu <textInFile> là dữ liệu của file text.
    * 
    */

    long i;
    long length = textInFile.length();
    for (i=0; i<length; i++)
    {
        // duyệt <textInFile> nếu gặp trường hợp ngoại lệ của mã morse thì trả về false
        
        char temp = char(textInFile[i]);
        if ((temp != '.') && (temp != '/') && (temp != ' ') && (temp != '-') && (temp != '\n') && (temp != '\0'))
            return false;
    }
    return true;
}

void morse2text(string& mystring, ofstream &filera)
{
    /* thủ tục thực hiện giải mã <mystring> (dữ liệu nhận được từ file morse) và ghi vào <filera> 
    *  
    *  Input: <mystring> : dữ liệu file morse sau khi đã chuyển thành string và xử lí bằng hàm textFile2string.
    *         <filera>   : file dữ liệu dùng để ghi kết quả sau khi thủ tục thực hiện.
    */
    
    int pos = 0;
    string token;
    int line = 1;

    while ( (pos = mystring.find(" ")) != string::npos)                   // tìm dấu ngăn cách gần nhất để tách 1 kí tự morse
    {
        token = mystring.substr(0, pos);                                  //tách kí tự morse ra để xử lí
        int i;
        for (i = 0; i <= ALL; i++)
        {
            // giải mã morse->text

            if ((token == morse[i]) && (i != ALL))
            {
                token = text[i];
                filera << token;
                break;
            }
            else if ((i==ALL) && (token.c_str()[0] != '\n')) 
            {
                //xử lí lỗi Error: Invalid Morse code...

                filera << "*";
                cerr << "Error: Invalid Morse code "<< token << " on line "<< line << endl;        
            }
        }    
        if (token.c_str()[0] == '\n')
            {
                // Xử lí khi file morse có dấu xuống dòng

                token = "\n";
                line++;
                filera << token;
                mystring.erase(0,1);                                      // chỉ xóa dấu xuống dòng
                continue;                                                 // bỏ qua lệnh xoá token bên dưới
            }
        mystring.erase(0, pos+1);                                         // xóa kí tự morse đã xử lí để tiến hành xử lí từ tiếp theo
    }
}

void text2morse(string& mystring, ofstream &filera)
{
    /* thủ tục mã hóa <mystring> (dữ liệu nhận được từ file text) và ghi dữ liệu được mã hóa vào <filera>
    *
    *  Input: <mystring> dữ liệu text cần mã hóa sau khi đã chuyển về string.
    *         <filera> file đầu ra cần ghi vào sau khi đã mã hóa dữ liệu của file text.
    *  Output: ghi dữ liệu mã hóa ra <filera>
    *          hiển thị lỗi nếu gặp chữ không mã hóa được.
    * 
    */

    long length = mystring.length();
    int line = 1;

    for ( int i = 0 ; i < length; i++)                                     // duyệt chuỗi mystring
    {
        int j;
        for (j = 0; j < ALL; j++) 
        {
            // mã hóa text -> morse

            if ( (mystring[i] == text[j].c_str()[0]) && (text[j].c_str()[0] != '#'))
            {
                if (mystring[i+1] != '\n')
                    filera << morse[j] << ' ';                             // ngăn cách các chữ của file morse = dấu cách
                else                                 
                    filera << morse[j];                                    // nếu chữ tiếp theo là \n thì không cần dấu cách
                break;
            }
        }
        
        if (mystring[i] == '\n')
            {
                // xử lí khi có dấu xuống dòng

                filera << "\n";
                line++;
            }
        else if ((mystring[i] != '\n') && (j==ALL))                        // xử lí ngoại lệ không mã hóa được
            cerr << "Error: Unrecognised character " << mystring[i] << " on line "<< line<< '\n';        
    }
}

#endif