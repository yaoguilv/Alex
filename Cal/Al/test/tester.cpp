#include <iostream>
#include <string>
#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C1/Unit3_Stacks/Stack.h"
#include "C4/U1/CC.h"

using namespace std;

int main(int argc, char ** argv)
{
    Graph * myG = new Graph(13);
    myG->addEdge(0, 1);
    myG->addEdge(0, 2);
    myG->addEdge(0, 5);
    myG->addEdge(0, 6);
    myG->addEdge(5, 3);
    myG->addEdge(5, 4);
    myG->addEdge(3, 4);
    myG->addEdge(4, 6);
    myG->addEdge(7, 8);
    myG->addEdge(9, 10);
    myG->addEdge(9, 11);
    myG->addEdge(9, 12);
    myG->addEdge(11, 12);

    string outContext = myG->toString();
    cout << outContext << endl;

    CC * cc = new CC(myG);
    int M = cc.count();
    cout << M << " components" << endl;

    // refer:
    /* int s = 0; */
    /* BreadthFirstPaths * search = new BreadthFirstPaths(myG, s); */
    /* for(int v = 0; v < myG->getV(); v++) */
    /* { */
    /*     cout << to_string(s) << " to " + to_string(v) + ": "; */
    /*     if(search->hasPathTo(v)) */
    /*     { */
    /*         Stack<int> * resultStack = search->pathTo(v); */
    /*         while(!resultStack->isEmpty()) */
    /*         { */
    /*             int x = resultStack->pop(); */
    /*             if(x == s) cout << x; */
    /*             else cout << "-" << to_string(x); */
    /*         } */
    /*     } */
    /*     cout << endl; */
    /* } */

        // java:
        Bag<Integer>[] components;
        components = (Bag<Integer>[]) new Bag<?>[M];
        for(int i = 0; i < M; i++)
            components[i] = new Bag<Integer>();
        for(int v = 0; v < myG.V(); v++)
            components[cc.id(v)].add(v);
        for(int i = 0; i < M; i++)
        {
            for(int v : components[i])
                StdLib.StdOut.print(v + " ");
            StdLib.StdOut.println();
        }

}
