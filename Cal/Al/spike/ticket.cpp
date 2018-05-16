#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class DirectE
{
    public:
        int n;
        DirectE()
        {
            n = 55;
        }
};

int main()
{
    DirectE* myE;
    DirectE mydd;
    myE = new DirectE[3];
    myE[0].n = 3;
    cout << myE[0].n << "  " << myE[1].n << endl;
    cout << mydd.n << endl;
    return 0;
}
