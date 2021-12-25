#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define ALL 65
using namespace std;

bool FileExist1(const string &filename)
{
    // Kiem tra file dau vao co ton tai khong
    ifstream f(filename.c_str());
    return f.good();//Check whether the status of the stream is normal. Return true when the error status flags (eofbit, failbit and badbit) are not set
}

bool checkIfMorse(const string& textInFile)
{
    // Kiem tra string tu file dau vao la morse hay text
    long i;
    for (i=0; i<textInFile.length(); i++)
    {
        char temp = char(textInFile[i]);
        if ((temp != '.') && (temp != '/') && (temp != ' ') && (temp != '-') && (temp != '\n') && (temp != '\0'))
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    char temp[1];
    string mystring;
    ofstream filera;
    ifstream filevao;

    // Open filevao and get string into mystring
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
    // filevao.open("1.txt", ios::in);
    mystring = string((istreambuf_iterator<char>(filevao)), istreambuf_iterator<char>());
    cout << int(checkIfMorse(mystring)) << endl;
    filevao.close();

    // Warning: FILENAME already if no => exit
    if (FileExist1(argv[2])) 
    {
        cout << "Warning: " << argv[2] << " already exists. Do you wish to overwrite (y,n)? ";
        char yesNo;
        cin >> yesNo;
        if (yesNo != 'y')
            exit(1); 
    }
    filera.open(argv[2], ios::out | ios::trunc);
    // filera.open("2.txt", ios::out | ios::trunc);

    string ra[ALL]={
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
    
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
    
    "1","2","3","4","5","6","7","8","9","0",
    
    " ","#", "."
    };

    string vao[ALL]={
    ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    
        ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    
    ".----", "..---", "...--","....-", ".....", "-....", "--...", "---..", "----.", "-----",
    
    "/","........", ".-.-.-"
    };

    int pos = 0;
    string token;
    int line = 1;

    while ( (pos = mystring.find(" ")) != string::npos) 
    {
        token = mystring.substr(0, pos);
        int i;
        for (i = 0; i <= ALL; i++)
        {
            if ((token == vao[i]) && (i != 65))
            {
                token = ra[i];
                filera << token;
                break;
            }
            else if ((i==ALL) && (token.c_str()[0] != '\n')) 
            {
                filera << "*";
                cerr << "Error: Invalid Morse code "<< token << " on line "<< line << endl;        
            }
        }    
        if (token.c_str()[0] == '\n')
            {
                // mystring.insert(0," ");
                token = "\n";
                line++;
                filera << token;
                mystring.erase(1,2);
                continue;
            }
        mystring.erase(0, pos+1);
    }
    filera.close();

}