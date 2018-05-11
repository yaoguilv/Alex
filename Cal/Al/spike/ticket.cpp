#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class ewdA
{
    public:
        int edwM;
        ewdA(int inM)
        {
            edwM = inM;
        }
        int getM()
        {
            return edwM;
        }
};

int main()
{
    ewdA** p;
    p = new ewdA*[3];
    p[0] = new ewdA(3);
    p[1] = new ewdA(5);
    p[2] = new ewdA(8);
    cout << p[0]->getM() << endl;
    cout << p[1]->getM() << endl;
    cout << p[2]->getM() << endl;

    return 0;
}
