#ifndef EDGE_H
#define EDGE_H

#include <string>

using namespace std;

class Edge {
private:
    // one vertex
    int v;
    // the other vertex
    int w;
    // edge weight
    double weight;
public:
    Edge(int v, int w, double weight)
    {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }

    double getWeight()
    {
        return weight;
    }

    int either()
    {
        return v;
    }

    int other(int vertex)
    {
        if(vertex == v)
            return w;
        else if(vertex == w)
            return v;
        else
            throw new RuntimeException("Inconsistent edge");
    }

    int compareTo(Edge * that)
    {
        if(this->weight() < that->weight())
            return -1;
        else if(this->weight() > that->weight())
            return +1;
        else
            return 0;
    }

    public string toString()
    {
        return string.format("%d-%d %.2f", v, w, weight);
    }
};
#endif
