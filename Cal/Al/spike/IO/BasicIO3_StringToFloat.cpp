#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    cout << "Hello ticket!" << endl;
    string mystr;
    float price;

    cout << "enter price: " << endl;
    getline(cin, mystr);
    // string to float
    stringstream(mystr) >> price;
    cout << "price is: " << price << endl;
    return 0;
}
