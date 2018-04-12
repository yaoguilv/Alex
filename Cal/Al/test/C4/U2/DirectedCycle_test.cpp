#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "C1/Unit3_Stacks/Stack.h"
#include "C4/U2/Digraph.h"
#include "C4/U2/DirectedCycle.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/home/cc/Downloads/.temp/Workspace/Alex/Cal/Al/data/DirectedCycle_data.txt";
    Digraph *G = new Digraph(fileName);
    DirectedCycle * myCycle = new DirectedCycle(G);
    cout << myCycle->hasCycle() << endl;
    Stack<int> * myStack = myCycle->getCycle();
    while(!myStack->isEmpty())
    {
        cout << myStack->pop() << endl;
    }
}
