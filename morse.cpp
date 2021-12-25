#include <iostream>
#include <fstream>
#include <string>

#define MAX 255

using namespace std;

bool FileExist1(const string &filename)
{
    // Kiem tra file dau vao co ton tai khong
    ifstream f(filename.c_str());
    return f.good();//Check whether the status of the stream is normal. Return true when the error status flags (eofbit, failbit and badbit) are not set
}

int main(int argc, char *argv[])
{
    char temp[MAX];
    string mystring;
    ofstream filera;
    ifstream filevao;

    try
    {
        // Error: FILENAME could not be opened
        filevao.open(argv[1], ios::in);
        if (filevao.fail())
            throw "could not be opened";
    }
    catch (const char* &err)
    {
        cerr<< "Error: "<< argv[1]<< " "<< err<< endl;
        exit(1);
    }

    // Warning: FILENAME already ...
    if (FileExist1(argv[2])) 
    {
        cout << "Warning: " << argv[2] << " already exists. Do you wish to overwrite (y,n)? ";
        char yesNo;
        cin >> yesNo;
        if (yesNo != 'y')
            exit(1); 
    }

    filera.open(argv[2], ios::out | ios::trunc);

    while (!filevao.eof())
    {
        filevao.getline(temp, MAX);
        mystring = string(temp);
    }

    filevao.close();

    string ra[64]={
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
    
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
    
    "1","2","3","4","5","6","7","8","9","0",
    
    " ","#"
    };

    string vao[64]={
    ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    
        ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    
    ".----", "..---", "...--","....-", ".....", "-....", "--...", "---..", "----.", "-----",
    
    "/","........"
    };

    string phan_tach = " ";
    int pos = 0;
    string token;

    int line = 1;
    while ((pos = mystring.find(phan_tach)) != string::npos) 
    {
        token = mystring.substr(0, pos);
        
        for (int i = 0; i <= 64; i++)
        {
            if ((token == vao[i]) && (i != 64))
            {
                token = ra[i];
                filera << token;
                break;
            }
            else if (i==64)
            {
                filera << "*";
                cerr << "Error: Invalid Morse code "<< token << "on line "<< line;
                if (token.c_str()[0] == '\n')
                    line++;
            }
        }
        mystring.erase(0, pos + phan_tach.length());
    }
    filera.close();

}