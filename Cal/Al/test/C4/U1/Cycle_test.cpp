#include <iostream>
#include <string>
#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C1/Unit3_Stacks/Stack.h"
#include "C4/U1/Cycle.h"

using namespace std;

int main(int argc, char ** argv)
{
    Graph * myG = new Graph(4);
    myG->addEdge(0, 1);
    myG->addEdge(0, 2);
    myG->addEdge(0, 3);
    myG->addEdge(2, 3);

    cout << "myG:" << endl;
    string outContext = myG->toString();
    cout << outContext << endl;

    Cycle * myCycle = new Cycle(myG);
    cout << "myG has Cycle:" << endl;
    cout << myCycle->hasCycle() << endl;

    cout << endl;

    Graph * myG2 = new Graph(4);
    myG2->addEdge(0, 1);
    myG2->addEdge(0, 2);
    myG2->addEdge(0, 3);

    cout << "myG2:" << endl;
    string outContext2 = myG2->toString();
    cout << outContext2 << endl;

    Cycle * myCycle2 = new Cycle(myG2);
    cout << "myG2 has Cycle:" << endl;
    cout << myCycle2->hasCycle() << endl;
}
