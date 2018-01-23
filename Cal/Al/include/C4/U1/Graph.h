#ifndef GRAPH_H
#define GRAPH_H
#include "C1/Unit3_Stacks/Bag.h"
#include <string>

using namespace std;

class Graph {
private:
    // number of vertices
    int V;
    // number of edges
    int E;

public:
    // adjancency lists
    Bag<int> ** adj;

    Graph(int V)
    {
        this->V = V;
        this->E = 0;
        // Create array of lists.
        adj = new Bag<int>*[V];
        // Initialize all lists
        for(int v = 0; v < V; v++)
            // to empty
            adj[v] = new Bag<int>();
    }

    int getV()
    {
        return V;
    }

    int getE()
    {
        return E;
    }

    void addEdge(int v, int w)
    {
        // Add w to v's list.
        adj[v]->add(w);
        // Add v to w's list.
        adj[w]->add(v);
        E++;
    }

    static int degree(Graph * G, int v)
    {
        int degree = 0;
        for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
            degree++;
        return degree;
    }

    static int maxDegree(Graph * G)
    {
        int max = 0;
        for(int v = 0; v < G->getV(); v++)
        {
            if(degree(G, v) > max)
                max = degree(G, v);
        }
        return max;
    }

    static int avgDegree(Graph * G)
    {
        return 2 * G->getE() / G->getV();
    }

    static int numberOfSelfLoops(Graph * G)
    {
        int count = 0;
        for(int v = 0; v < G->getV(); v++)
            for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
                if(v == myIt->item) count++;
        // each edge counted twice
        return count/2;
    }

    string toString()
    {
        string s = to_string(V) + " vertices, " + to_string(E) + " edges\n";
        for(int v = 0; v < V; v++)
        {
            s += to_string(v) + ": ";
            for(Bag<int>::Node * myIt = this->adj[v]->first; myIt != nullptr; myIt = myIt->next)
                s += to_string(myIt->item) + " ";
            s += "\n";
        }
        return s;
    }
};
#endif
