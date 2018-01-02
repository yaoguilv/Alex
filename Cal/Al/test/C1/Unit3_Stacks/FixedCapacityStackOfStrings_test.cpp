#include <iostream>
#include <string>
#include "C1/U3/FixedCapacityStackOfStrings.h"

using namespace std;

int main()
{
    FixedCapacityStackOfStrings* s = new FixedCapacityStackOfStrings(100);
    cout << "please input int to stack(0 to exit, -1 to pop one int):" << endl;
    string inputStr = "";
    getline(cin, inputStr);
    while(stoi(inputStr) != 0)
    {
        if(stoi(inputStr) != -1)
            s->push(inputStr);
        else
            cout << s->pop() << endl;
        getline(cin, inputStr);
    }
    cout << "(" + to_string(s->size()) + " left on stack)" << endl;
}
