#include <string>

using namespace std;

class Accumulator
{
private:
    double total;
    int N;
public:
    Accumulator();
    void addDataValue(double val);
    double mean();
    string toString();
};
