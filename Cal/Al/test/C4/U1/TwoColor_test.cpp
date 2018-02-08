#include <iostream>
#include <string>
#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U1/TwoColor.h"

using namespace std;

int main(int argc, char ** argv)
{
   Graph * myG = new Graph(4);
    myG->addEdge(0, 1);
    myG->addEdge(1, 2);
    myG->addEdge(2, 3);
    myG->addEdge(3, 0);

    cout << "myG:" << endl;
    string outContext = myG->toString();
    cout << outContext;

    cout << "myG is Bipartite:" << endl;
    TwoColor * myTwoColor = new TwoColor(myG);
    cout << myTwoColor->isBipartite() << endl;

    cout << endl << endl;

   Graph * myG2 = new Graph(4);
    myG2->addEdge(0, 1);
    myG2->addEdge(1, 2);
    myG2->addEdge(2, 3);
    myG2->addEdge(3, 1);

    cout << "myG2:" << endl;
    string outContext2 = myG2->toString();
    cout << outContext2;

    cout << "myG2 is Bipartite:" << endl;
    TwoColor * myTwoColor2 = new TwoColor(myG2);
    cout << myTwoColor2->isBipartite() << endl;
}
