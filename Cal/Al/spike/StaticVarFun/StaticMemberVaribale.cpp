#include <iostream>

using namespace std;

class A
{
public:
    static int m;
    void setM(int n)
    {
        m = n;
    }

    int getM()
    {
        return m;
    }
};

// this sentence is important
// here define the static variable, allocate the memory
// above code is just declaring the static variable, do not allocate memory
int A::m;

int main()
{
    A * myA = new A();
    myA->setM(2);
    cout << myA->getM() << endl;
    return 0;
}
