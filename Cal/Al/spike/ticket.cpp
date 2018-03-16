#include <iostream>

using namespace std;

class A
{
public:
    virtual int getN() = 0;
};

class B : public A
{
    /* public: */
public:
        int getN()
        {
            return 3;
        }

    int getM()
    {
        return 2;
    }
};

int main(int argc, char ** argv)
{
    B * myB = new B();
    cout << myB->getN() << endl;
    cout << myB->getM() << endl;
    return 0;
}
