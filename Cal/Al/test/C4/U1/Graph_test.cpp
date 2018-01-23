#include <iostream>
#include <string>
#include "C4/U1/Graph.h"

using namespace std;

int main(int argc, char ** argv)
{
    Graph * myG = new Graph(7);
    myG->addEdge(0, 1);
    myG->addEdge(0, 2);
    myG->addEdge(0, 5);
    myG->addEdge(0, 6);
    myG->addEdge(5, 3);
    myG->addEdge(5, 4);
    myG->addEdge(3, 4);
    myG->addEdge(4, 6);
    string outContext = myG->toString();
    cout << outContext << endl;
}
