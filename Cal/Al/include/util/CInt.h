#include "util/Comparable.h"

using namespace std;

class CInt : public Comparable {
private:
    int value;
public:
    CInt(){};
    CInt(int inValue);
    int getInt();
    int compareTo(Comparable * that);
};
