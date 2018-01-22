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
        // adjancency lists
        Bag<int> * adj;

    public:
        Graph(int V)
        {
            this->V = V;
            this->E = 0;
            // Create array of lists.
            adj = new Bag<int>[V];
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
        adj[w]->add(v).
        E++;
    }

    static int degree(Graph * G, int v)
    {
        int degree = 0;
        for(auto w : G->adj(v))
            degree++;
        return degree;
    }

    static int maxDegree(Graph * G)
    {
        int max = 0;
        for(int v = 0; v < G->V(); v++)
        {
            if(degree(G, v) > max)
                max = degree(G, v);
        }
        return max;
    }

    static int avgDegree(Graph * G)
    {
        return 2 * G->E() / G->V();
    }

    static int numberOfSelfLoops(Graph * G)
    {
        int count = 0;
        for(int v = 0; v < G->V(); v++)
            for(auto w : G->adj[v])
                if(v == w) count++;
        // each edge counted twice
        return count/2;
    }

    string toString()
    {
        string s = V + " vertices, " + E + " edges\n";
        for(int v = 0; v < V; v++)
        {
            s += v + ": ";
            for(auto w : this->adj[v])
                s += w + " ";
            s += "\n";
        }
        return s;
    }
};
#endif
