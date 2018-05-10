#include "C4/U4/DirectedEdge.h"

DirectedEdge::DirectedEdge(int inV, int inW, double inWeight)
{
    this->v = inV;
    this->w = inW;
    this->weight = inWeight;
}

double DirectedEdge::getWeight()
{
    return weight;
}

int DirectedEdge::from()
{
    return v;
}

int DirectedEdge::to()
{
    return w;
}

string DirectedEdge::toString()
{
    string strV = to_string(v);
    string strW = to_string(w);
    string strWeight = to_string(weight);
    return strV + "->" + strW + " " + strWeight;
}
