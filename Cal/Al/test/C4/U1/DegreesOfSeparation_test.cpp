#include <iostream>
#include <string>
#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U1/SymbolGraph.h"
#include "C4/U1/BreadthFirstPaths.h"
#include "C4/U1/DegreesOfSeparation.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/home/cc/Downloads/.temp/Workspace/Alex/Cal/Al/bin/routes.txt";
    string delim = " ";
    SymbolGraph * sg = new SymbolGraph(fileName, delim);

    Graph * myG = sg->getG();
    string source = "JFK";
    if(!sg->contains(source))
    {
        cout << source << " not in database." << endl;
        return 0;
    }

    int s = sg->index(source);
    BreadthFirstPaths * bfs = new BreadthFirstPaths(myG, s);

    string inputTest;
    getline(cin, inputTest);
    while("q" != inputTest)
    {
        if(sg->contains(inputTest))
        {
            int t = sg->index(inputTest);
            if(bfs->hasPathTo(t))
            {
                Stack<int> * myPath = bfs->pathTo(t);
                while(!myPath->isEmpty())
                {
                    int x = myPath->pop();
                    cout << "    " << sg->name(x);
                }
                cout << endl;
            }
            else
                cout << "Not in database." << endl;
        }
        getline(cin, inputTest);
    }
}
