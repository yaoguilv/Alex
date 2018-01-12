#include <iostream>
#include <stirng>
#include "C2/U1/MyDate.h"
#include "C3/U1/SequentialSearchST.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;


    SequentialSearchST<MyDate, string> * myST = new SequentialSearchST<MyDate, string>();
    myST.put(1, "dd");
    myST.put(3, "gg");
    myST.put(2, "gew");
    System.out.println(myST.get(2));

    MyDate ** dat = new MyDate*[5];
    dat[0] = nullptr;
    dat[1] = new MyDate(1, 1, 2010);
    dat[2] = new MyDate(1, 1, 2017);
    dat[3] = new MyDate(1, 1, 2015);
    dat[4] = new MyDate(1, 1, 2012);

    for(int i = 1; i < 5; i++)
    {
        cout << dat[i]->toString() << endl;
    }
}

