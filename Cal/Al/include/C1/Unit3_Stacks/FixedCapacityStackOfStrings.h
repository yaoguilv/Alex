#include <string>

using namespace std;

class FixedCapacityStackOfStrings
{
private:
    string* a;
    int N;

public:
    FixedCapacityStackOfStrings(int cap);

    bool isEmpty();

    int size();

    void push(string item);

    string pop();
};
