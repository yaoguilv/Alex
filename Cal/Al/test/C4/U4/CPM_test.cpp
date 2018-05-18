#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C4/U4/DijkstraSP.h"
#include "util/CDouble.h"
#include "C4/U4/AcyclicLP.h"

using namespace std;

int main(int argc, char ** argv)
{
    ifstream inputFile;
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/jobsPC.txt";
    inputFile.open(fileName, fstream::in | fstream::out);
    vector<string> strArr;

    if(!inputFile.is_open())
    {
        cout << "open file failed!" << endl;
        return 0;
    }

    char buf[256];
    inputFile.getline(buf, 100);
    string strN = buf;
    int N = stoi(strN);

    EdgeWeightedDigraph* G = new EdgeWeightedDigraph(2 * N + 2);
    int s = 2 * N, t = 2 * N + 1;
    string sp = " ";
    for(int i = 0; i < N; i++)
    {
        inputFile.getline(buf, 100);
        string strToSplit = buf;
        strArr.clear();
        CString::split(strToSplit, sp, strArr);

        double duration = stod(strArr[0]);
        G->addEdge(new DirectedEdge(i, i + N, duration));
        G->addEdge(new DirectedEdge(s, i, 0.0));
        G->addEdge(new DirectedEdge(i + N, t, 0.0));
        for(int j = 1; j < strArr.size(); j++)
        {
            int successor = stoi(strArr[j]);
            G->addEdge(new DirectedEdge(i + N, successor, 0.0));
        }
    }

    inputFile.close();

    AcyclicLP* lp = new AcyclicLP(G, s);

    cout << "Start times:" << endl;
    for(int i = 0; i < N; i++)
        cout << i << " : "<< lp->getDistTo(i) << endl;
    cout << "Finish time: " << lp->getDistTo(t) << endl;

    return 0;
}
