#include <iostream>
#include <string>
#include "C2/U1/MyDate.h"
#include "C3/U1/BinarySearchST.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;

    BinarySearchST<MyDate *, string> * myBS = new BinarySearchST<MyDate *, string>(3);
    cout << "now size is :" << endl;
    cout << myBS->size() << endl;
    MyDate ** dat = new MyDate*[3];
    dat[0] = new MyDate(1, 1, 2015);
    dat[1] = new MyDate(1, 1, 2010);
    dat[2] = new MyDate(1, 1, 2017);

    myBS->put(dat[0], "bbb");
    myBS->put(dat[1], "aaa");
    myBS->put(dat[2], "ccc");

    string ret = myBS->get(dat[1]);
    cout << "2010:" << ret << endl;

    cout << "max:" << myBS->max()->toString() << endl;

    cout << "min:" << myBS->min()->toString() << endl;
}

