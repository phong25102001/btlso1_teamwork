#include <fstream>
#include <iostream>

using namespace std;

int main()
{ 
  string input[100];
  char kt;
  int i=0,dem;
  fstream filevao;
  filevao.open("1.txt", ios::in);
//   if (filevao == 0)
//   {
//     cout << "Cannot read file!";
//     return 0;
//   }
    while (!filevao.eof())
    {
      filevao.get(kt);
      input[i] = kt;
      i++;
      dem=i;
    }
  
 for(i=0;i<dem-1;i++)
 {
 	cout<<input[i];
 }
  filevao.close();
  cout<<endl;
  string vao[63]={
  "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
  
  "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
  
  "1","2","3","4","5","6","7","8","9","0",
  
  " "
  };
  string ra[63]={
  ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  
    ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  
   ".----", "..---", "...--","....-", ".....", "-....", "--...", "---..", "----.", "-----",
   
   "/"
  };
                    
    for(int i=0;i<dem-1;i++)
	{
		for(int j=0;j<63;j++)
		{
			if(input[i]==vao[j])
			{
				input[i]=ra[j];
			}
		}
    }   
 for(i=0;i<dem-1;i++)
 {
 	cout<<" "<<input[i];
 }           
 fstream filera;
 filera.open("2.txt",ios::out);
//    if (filera == 0)
//   {
//     cout << "Cannot found file!";
//     return 0;
//   }  
  for(int i=0;i<dem-1;i++)
  {
  	filera<<input[i];
  }
  filera.close();
}