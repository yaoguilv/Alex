#include <iostream>
#include <string>
#include "C4/U4/DirectedEdge.h"

using namespace std;

int main(int argc, char ** argv)
{
    DirectedEdge* myDE = new DirectedEdge(1, 2, 5.3);
    cout << myDE->getWeight() << endl;
    cout << myDE->from() << endl;
    cout << myDE->to() << endl;
    cout << myDE->toString() << endl;
}
