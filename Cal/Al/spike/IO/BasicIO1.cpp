#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello ticket!" << endl;
    cout << "input a string with whitespace: " << endl;
    string str1;
    /*cin extraction: whitespaces, tabs, new-line...*/
    /*cannot receive a phrase or an entire sentence*/
    cin >> str1;
    cout << "Hello " << str1 << endl;
}
