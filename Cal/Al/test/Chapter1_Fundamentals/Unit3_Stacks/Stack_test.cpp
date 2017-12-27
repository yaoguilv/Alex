#include <iostream>
#include <string>
#include "Chapter1_Fundamentals/Unit3_Stacks/Stack.h"

using namespace std;

int main()
{
    Stack<int> * st = new Stack<int>();
    cout << "init stack is: " << endl;
    cout << st->size() << endl;
    cout << "is empty: " << endl;
    cout << st->isEmpty() << endl;

    st->push(3);
    cout << "pop 3:" << endl;
    cout << st->pop() << endl;;
    st->push(5);
    st->push(6);
    cout << "push two int, then size is: " << endl;
    cout << st->size() << endl;
}
