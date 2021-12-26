#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream filevao("2.txt", ios::in);
    cout << string((istreambuf_iterator<char>(filevao)), istreambuf_iterator<char>());
    filevao.close();
    filevao.open("2.txt", ios::in);
    cout << string((istreambuf_iterator<char>(filevao)), istreambuf_iterator<char>());
    filevao.close();
    return 0;
}