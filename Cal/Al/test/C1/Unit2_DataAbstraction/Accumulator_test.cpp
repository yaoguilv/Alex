#include <iostream>
#include "C1/U2/Accumulator.h"

using namespace std;

int main()
{
        int T = 6;
        Accumulator* a = new Accumulator();
        for(int t = 1; t < T; t++)
            a->addDataValue(t);
        a->addDataValue(13);

        cout << a->toString() << endl;
}
