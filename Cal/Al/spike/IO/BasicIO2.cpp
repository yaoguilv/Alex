#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello ticket!" << endl;
    cout << "input the string with whitespace: " << endl;
    string str1;
    // get the whole line
    // donot consider the whitespace,tab
    getline(cin, str1);
    cout << "Hello " << str1 << endl;
}
