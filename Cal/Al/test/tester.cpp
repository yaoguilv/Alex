#include <iostream>
#include <string>
#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U1/SymbolGraph.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = argv[1];
    string delim = argv[2];
    SymbolGraph * sg = new SymbolGraph(fileName, delim);

    Graph * myG = sg->getG();

    string inputStr;
    cin >> inputStr;
    while(!inputStr.empty())
    {
        string source = inputStr;
        int adjIndex = sg->index(source);

        for(Bag<int>::Node * myIt = myG->adj[adjIndex]->first; myIt != nullptr; myIt = myIt->next)
            cout << "  " + sg->name(myIt->item);
        cin >> inputStr;
    }
}
