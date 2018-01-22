#include <iostream>
#include <string>
#include "C2/U1/MyDate.h"
#include "C3/U4/SeparateChainingHashST.h"

using namespace std;

int main(int argc, char ** argv)
{
    SeparateChainingHashST<MyDate*, string> * mySCH = new SeparateChainingHashST<MyDate*, string>();

    MyDate ** dat = new MyDate*[3];
    dat[0] = new MyDate(1, 1, 2015);
    dat[1] = new MyDate(1, 1, 2010);
    dat[2] = new MyDate(1, 1, 2017);

    mySCH->put(dat[0], "bbb");
    mySCH->put(dat[1], "aaa");
    mySCH->put(dat[2], "ccc");

    cout << "key 2010's value is:" << endl;
    cout << mySCH->get(dat[1]) << endl;
    cout << "key 2015's value is:" << endl;
    cout << mySCH->get(dat[0]) << endl;
    cout << "key 2017's value is:" << endl;
    cout << mySCH->get(dat[2]) << endl;
}
