#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>

#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "util/CDouble.h"
#include "C4/U4/BellmanFordSP.h"
#include "C4/U4/EdgeWeightedDirectedCycle.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/tinyEWDnc.txt";
    EdgeWeightedDigraph* myEWD = new EdgeWeightedDigraph(fileName);

    int s = 0;
    BellmanFordSP* sp = new BellmanFordSP(myEWD, s);

    if(sp->hasNegativeCycle())
    {
        vector<DirectedEdge*> cycleEdges;
        sp->negativeCycle(cycleEdges);
        for(vector<DirectedEdge*>::iterator it = cycleEdges.begin(); it != cycleEdges.end(); it++)
        {
            DirectedEdge* e = *it;
            cout << e->toString() << "    ";
        }
        cout << endl;

    }
    else
    {
        for(int t = 0; t < myEWD->getV(); t++)
        {
            cout << s << " to " << t;
            cout << " (" << sp->getDistTo(t) << ")";
            if(sp->hasPathTo(t))
            {
                vector<DirectedEdge*> path;
                sp->getPathTo(t, path);
                for(vector<DirectedEdge*>::iterator it = path.begin(); it != path.end(); it++)
                {
                    DirectedEdge* e = *it;
                    cout << e->toString() << "    ";
                }
            }
            cout << endl;
        }


    }
    return 0;
}

