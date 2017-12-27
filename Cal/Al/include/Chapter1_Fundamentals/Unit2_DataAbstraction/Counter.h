#include <string>

using namespace std;

class Counter {
private:
    string name;
    int count;

public:
    Counter(string id);
    void increment();
    int tally();
    string toString();
};
