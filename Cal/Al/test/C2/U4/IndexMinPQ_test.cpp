#include <iostream>
#include "C2/U1/MyDate.h"
#include "C2/U4/IndexMinPQ.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;

    IndexMinPQ* myMinPQ = new IndexMinPQ(3);
    cout << "isEmpty: " << endl;
    cout << myMinPQ->isEmpty() << endl;

    myMinPQ->insert(1, new MyDate(1, 1, 2010));
    cout << "now size: " << endl;
    cout << myMinPQ->size() << endl;

    myMinPQ->insert(2, new MyDate(1, 1, 2017));
    myMinPQ->insert(3, new MyDate(1, 1, 2015));
    myMinPQ->insert(4, new MyDate(1, 1, 2005));
    cout << "now size: " << endl;
    cout << myMinPQ->size() << endl;

    MyDate* myDat = dynamic_cast<MyDate*>(myMinPQ->minKey());
    cout << "Min Key: " << endl;
    cout << myDat->toString() << endl;
    cout << "now size: " << endl;
    cout << myMinPQ->size() << endl;

    cout << "delete min:" << endl;
    cout << myMinPQ->delMin() << endl;
    cout << "now size:" << endl;
    cout << myMinPQ->size() << endl;
    cout << "now min key:" << endl;
    myDat = dynamic_cast<MyDate*>(myMinPQ->minKey());
    cout << myDat->toString() << endl;

    cout << "change the value of seconde min to min,";
    MyDate * newDate = new MyDate(1, 1, 2009);
    myMinPQ->change(3, newDate);
    myDat = dynamic_cast<MyDate*>(myMinPQ->minKey());
    cout << "now the min:" << endl;
    cout << myDat->toString() << endl;
}
