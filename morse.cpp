#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
    char temp[255];
    std::string mystring;
    ifstream filevao("1.txt");
    while (!filevao.eof()){
        filevao.getline(temp, 255);
        mystring = std::string(temp);
        std::cout << temp << std::endl;
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
std::string phan_tach = " ";
int pos = 0;
str:string token;
while ((pos = mystring.find(phan_tach)) != std::string::npos) {
    token = mystring.substr(0, pos);
    for (int i = 0; i < 64; i++){
        if (token == vao[i]){
            token = ra[i];
            cout << token;
        }

    }
    mystring.erase(0, pos + phan_tach.length());
}
}