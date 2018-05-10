#ifndef DIRECTEDEDGE_H
#define DIRECTEDEDGE_H

#include <string>

using namespace std;

class DirectedEdge {
private:
    // edge source
    int v;
    // edge target
    int w;
    // edge weight
    double weight;

public:
    DirectedEdge(int inV, int inW, double inWeihgt);
    double getWeight();
    int from();
    int to();
    string toString();
};

#endif
