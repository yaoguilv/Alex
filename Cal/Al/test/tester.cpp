#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U2/Digraph.h"
#include "C4/U2/DirectedDFS.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/home/cc/Downloads/.temp/Workspace/Alex/Cal/Al/data/tinyDG.txt";
    Digraph *G = new Digraph(fileName);
    vector<int> sources;
    sources.push_back(1);
    sources.push_back(2);
    sources.push_back(6);

    DirectedDFS * reachable = new DirectedDFS(G, sources);

    for(int i = 0; i < G->getV(); i++)
        if(reachable->getMarked(i))
            cout << i << " ";
    cout << endl;
}
#include "C4/U2/DirectedCycle.h"
