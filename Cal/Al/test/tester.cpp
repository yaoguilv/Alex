#include <iostream>
#include "C2/U1/MyDate.h"
#include "C2/U4/Heapsort.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;

    MyDate ** dat = new MyDate*[4];
    dat[0] = nullptr;
    dat[0] = new MyDate(1, 1, 2010);
    dat[1] = new MyDate(1, 1, 2017);
    dat[2] = new MyDate(1, 1, 2015);

    Heapsort::sort((Comparable **)dat, 4);
    for(int i = 1; i < 4; i++)
    {
        cout << dat[i]->toString() << endl;
    }
}

