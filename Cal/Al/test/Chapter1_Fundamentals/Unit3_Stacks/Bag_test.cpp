#include <iostream>
#include <string>
#include "Chapter1_Fundamentals/Unit3_Stacks/Bag.h"

using namespace std;

int main()
{
    Bag<int> * myBag = new Bag<int>();
    cout << "init Bag is Empty? " << endl;
    cout << myBag->isEmpty() << endl;
    myBag->add(2);
    cout << "now Bag is Empty? " << endl;
    cout << myBag->isEmpty() << endl;
}
