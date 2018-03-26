#include <string>
#include "util/Comparable.h"

using namespace std;

class MyString : public Comparable {
private:
    string str;
public:
    MyString(){};
    MyString(string inStr);
    string getStr();
    int compareTo(Comparable * that);
    string toString();
};
