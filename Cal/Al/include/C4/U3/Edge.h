#ifndef EDGE_H
#define EDGE_H

#include <string>
#include "util/Comparable.h"

using namespace std;

class Edge : public Comparable{
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
    }

    int compareTo(Comparable * that)
    {
        Edge * thatEdge = dynamic_cast<Edge*>(that);
        if(this->getWeight() < thatEdge->getWeight())
            return -1;
        else if(this->getWeight() > thatEdge->getWeight())
            return +1;
        else
            return 0;
    }

    string toString()
    {
        string strV = to_string(v);
        string strW = to_string(w);
        string strWeight = to_string(weight);
        return strV + "-" + strW + " " + strWeight;
    }
};
#endif
