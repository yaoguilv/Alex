#include <iostream>
#include <algorithm>
#include <vector>
#include "C1/U2/Counter.h"

using namespace std;

int main()
{
    int T = 12;
    Counter* heads = new Counter("heads");
    Counter* tails = new Counter("tails");

    for(int t = 0; t < T; t++)
    {
        if(t % 3 == 0)
            heads->increment();
        else
            tails->increment();
    }

    cout << heads->toString() << endl;
    cout << tails->toString() << endl;

    int d = heads->tally() - tails->tally();
    cout << abs(d) << endl;
    return 0;
}
