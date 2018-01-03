#include <string>
#include "util/Comparable.h"

using namespace std;

class MyDate : public Comparable {
    private:
        int day;
        int month;
        int year;
    public:
        MyDate(int d, int m, int y);
        int getDay();
        int getMonth();
        int getYear();
        int compareTo(Comparable * that);
        string toString();
};
