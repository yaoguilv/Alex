#include <iostream>
#include "C2/U1/Insertion.h"
#include "C2/U1/MyDate.h"

using namespace std;

int main()
{
    cout << "Hello tester!" << endl;
    MyDate ** dat = new MyDate*[3];
    dat[0] = new MyDate(1, 1, 2010);
    dat[1] = new MyDate(1, 1, 2017);
    dat[2] = new MyDate(1, 1, 2015);

    Insertion::sort((Comparable **)dat, 3);
    for(int i = 0; i < 3; i++)
    {
        cout << dat[i]->toString() << endl;
    }
}
