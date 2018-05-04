#include <iostream>
#include <string>
#include <vector>
#include "C2/U1/MyDate.h"
#include "C2/U4/MinPQ.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;

    MinPQ* myMinPQ = new MinPQ(3);
    cout << "isEmpty: " << endl;
    cout << myMinPQ->isEmpty() << endl;

    myMinPQ->insert(new MyDate(1, 1, 2010));
    cout << "now size: " << endl;
    cout << myMinPQ->size() << endl;

    myMinPQ->insert(new MyDate(1, 1, 2017));
    myMinPQ->insert(new MyDate(1, 1, 2015));
    myMinPQ->insert(new MyDate(1, 1, 2005));
    cout << "now size: " << endl;
    cout << myMinPQ->size() << endl;

    MyDate* myDat = dynamic_cast<MyDate*>(myMinPQ->delMin());
    cout << "delete Min: " << endl;
    cout << myDat->toString() << endl;
    cout << "now size: " << endl;
    cout << myMinPQ->size() << endl;

}
