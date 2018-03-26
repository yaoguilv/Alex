#include "util/Comparable.h"

using namespace std;

class MyInt : public Comparable {
private:
    int value;
public:
    MyInt(){};
    MyInt(int inValue);
    int getInt();
    int compareTo(Comparable * that);
};
