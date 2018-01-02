#include <iostream>
#include <string>
#include "C1/U3/ResizingArrayStack.h"

using namespace std;

int main()
{
    ResizingArrayStack<int> * ras = new ResizingArrayStack<int>();
    cout << "init stack is: " << endl;
    cout << ras->size() << endl;
    ras->push(3);
    cout << "pop 3:" << endl;
    cout << ras->pop() << endl;;
    ras->push(5);
    ras->push(6);
    cout << "push two int, then size is: " << endl;
    cout << ras->size() << endl;
}
