#include <string>
#include "util/Comparable.h"

using namespace std;

class MyDate : Comparable {
    private:
        int day;
        int month;
        int year;
    public:
        MyDate(int d, int m, int y);
        int getDay();
        int getMonth();
        int getYear();
        int compareTo(MyDate * that);
        string toString();
};
