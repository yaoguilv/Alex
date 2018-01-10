#include <iostream>
#include "C2/U1/MyDate.h"
#include "C2/U4/MaxPQ.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;

    MaxPQ * myMaxPQ = new MaxPQ(3);
    cout << "isEmpty: " << endl;
    cout << myMaxPQ->isEmpty() << endl;

    myMaxPQ->insert(new MyDate(1, 1, 2010));
    cout << "now size: " << endl;
    cout << myMaxPQ->size() << endl;

    myMaxPQ->insert(new MyDate(1, 1, 2017));
    myMaxPQ->insert(new MyDate(1, 1, 2015));
    cout << "now size: " << endl;
    cout << myMaxPQ->size() << endl;


    MyDate * myDat = dynamic_cast<MyDate *>(myMaxPQ->delMax());
    cout << "delete Max: " << endl;
    cout << myDat->toString() << endl;
    cout << "now size: " << endl;
    cout << myMaxPQ->size() << endl;
}

