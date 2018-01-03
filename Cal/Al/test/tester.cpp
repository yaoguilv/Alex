#include <iostream>
#include "C2/U1/Selection.h"
#include "C2/U1/MyDate.h"

using namespace std;

int main()
{
    cout << "Hello tester!" << endl;
    MyDate ** dat = new MyDate*[3];
    *(dat) = new MyDate(1, 1, 2010);
    *(dat + 1) = new MyDate(1, 1, 2017);
    *(dat + 2) = new MyDate(1, 1, 2013);
    Selection::sort((Comparable **)dat, 3);
    for(int i = 0; i < 3; i++)
    {
        cout << dat[i]->toString() << endl;
    }
}
