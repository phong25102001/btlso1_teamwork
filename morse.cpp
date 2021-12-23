#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    char temp[255];
    string mystring;
    ofstream filera;
    ifstream filevao;

    try
    {
        filevao.open(argv[1], ios::in);
        if (filevao.fail())
            throw "Error opening file!";
    }
    catch (...)
    {
        cerr << argv[1]  << " could not be opened" << endl;
        exit(1);
    }

    filera.open(argv[2], ios::out | ios::trunc);

    while (!filevao.eof())
    {
        filevao.getline(temp, 255);
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

while ((pos = mystring.find(phan_tach)) != string::npos) {
    token = mystring.substr(0, pos);
    for (int i = 0; i < 64; i++){
        if (token == vao[i]){
            token = ra[i];
            filera << token;
        }

    }
    mystring.erase(0, pos + phan_tach.length());
}
filera.close();

}