#include <iostream>
#include <string>

using namespace std;

class MyString
{
private:
    string str;
public:
    MyString(){};
    MyString(string myStr)
    {
        str = myStr;
    }

    void setStr(string inStr)
    {
        str = inStr;
    }

    string getStr()
    {
        return str;
    }
};

int main(int argc, char ** argv)
{
    MyString * pStr;
    pStr = new MyString[3];
    pStr[0].setStr("aa");
    pStr[1].setStr("bb");
    pStr[2].setStr("cc");
    /* cout << pStr[0] << "  " << pStr[1] << "  " << pStr[2] << endl; */
    cout << pStr[0].getStr() << endl;
cout << pStr[1].getStr() << endl;
cout << pStr[2].getStr() << endl;

    return 0;
}
