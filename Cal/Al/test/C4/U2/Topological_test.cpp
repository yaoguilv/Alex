#include <iostream>
#include <string>
#include "C1/Unit3_Stacks/Queue.h"
#include "C1/Unit3_Stacks/Stack.h"
#include "C4/U2/SymbolDigraph.h"
#include "C4/U2/Topological.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/jobs.txt";
    string delim = "/";
    SymbolDigraph * sd = new SymbolDigraph(fileName, delim);

    Topological * top = new Topological(sd->getG());

    Stack<int> * order = top->getOrder();
    while(!order->isEmpty())
    {
        cout << sd->name(order->pop()) << endl;
    }
}
