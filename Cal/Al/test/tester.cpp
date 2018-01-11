#include <iostream>
#include "C2/U1/MyDate.h"
#include "C2/U4/Heapsort.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;

    MyDate ** dat = new MyDate*[5];
    dat[0] = nullptr;
    dat[1] = new MyDate(1, 1, 2010);
    dat[2] = new MyDate(1, 1, 2017);
    dat[3] = new MyDate(1, 1, 2015);
    dat[4] = new MyDate(1, 1, 2012);

    Heapsort::sort((Comparable **)dat, 5);
    for(int i = 1; i < 5; i++)
    {
        cout << dat[i]->toString() << endl;
    }
}

