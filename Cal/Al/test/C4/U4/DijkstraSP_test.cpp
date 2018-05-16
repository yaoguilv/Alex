#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C4/U4/DijkstraSP.h"
#include "util/CDouble.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/tinyEWD.txt";
    EdgeWeightedDigraph* myEWD = new EdgeWeightedDigraph(fileName);

    int s = 0;
    DijkstraSP* sp = new DijkstraSP(*myEWD, s);

    for(int t = 0; t < myEWD->getV(); t++)
    {
        cout << s << " to " << t;
        cout << " (" << sp->getDistTo(t) << ")";
        if(sp->hasPathTo(t))
        {
            stack<DirectedEdge*> path;
            sp->getPathTo(t, path);
            while(!path.empty())
            {
                DirectedEdge* e = path.top();
                path.pop();
                cout << e->toString() << "    ";
            }
        }
        cout << endl;
    }

    return 0;
}
