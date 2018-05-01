#include <iostream>
#include <string>
#include "C4/U2/Digraph.h"
#include "C4/U2/KosarajuSCC.h"
#include "C4/U3/Edge.h"

using namespace std;

int main(int argc, char ** argv)
{
    Edge * myE = new Edge(2, 3, 1.2);
    Edge * myE2 = new Edge(1, 3, 0.2);
    cout << myE2->compareTo(myE) << endl;
    cout << myE->toString() << endl;
}
