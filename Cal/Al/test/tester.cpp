#include <iostream>
#include <string>
#include "C4/U1/Graph.h"
#include "C4/U1/DepthFirstPaths.h"
#include "C1/Unit3_Stacks/Stack.h"

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

    int s = 0;
    DepthFirstPaths * search = new DepthFirstPaths(myG, s);
    for(int v = 0; v < myG->getV(); v++)
    {
        cout << to_string(s) << " to " + to_string(v) + ": ";
        if(search->hasPathTo(v))
        {
            Stack<int> * resultStack = search->pathTo(v);
            while(!resultStack->isEmpty())
            {
                int x = resultStack->pop();
                if(x == s) cout << x;
                else cout << "-" << to_string(x);
            }
        }
        cout << endl;
    }
}
