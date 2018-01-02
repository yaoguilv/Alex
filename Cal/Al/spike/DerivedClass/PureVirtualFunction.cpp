#include <iostream>

using namespace std;

class Comparable
{
public:
    // here must have a function body "{}"
    // or compile error will appear: undifined reference to "vtable for Comparable"
    virtual int compareTo(Comparable * that) {};
};

class Date : public Comparable
{
public:
    int N;
    int compareTo(Date * that)
    {
        if(this->N > that->N)
            return 1;
        return 0;
    }
};

int main()
{
    cout << "Hello Ticket!" << endl;
    Date * d1 = new Date();
    d1->N = 2;
    Date * d2 = new Date();
    d2->N = 5;
    int m = d2->compareTo(d1);
    cout << m << endl;
    return 0;

}
