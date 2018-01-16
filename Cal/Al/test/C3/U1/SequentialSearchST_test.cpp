#include <iostream>
#include <string>
#include "C2/U1/MyDate.h"
#include "C3/U1/SequentialSearchST.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;

    MyDate ** dat = new MyDate*[3];
    dat[0] = new MyDate(1, 1, 2015);
    dat[1] = new MyDate(1, 1, 2010);
    dat[2] = new MyDate(1, 1, 2017);

    SequentialSearchST<MyDate *, string> * myST = new SequentialSearchST<MyDate *, string>();
    string a = "aa";
    string b = "bb";
    string c = "cc";
    myST->put(dat[0], a);
    myST->put(dat[1], b);
    myST->put(dat[2], c);
    cout << myST->get(dat[1]) << endl;
}
