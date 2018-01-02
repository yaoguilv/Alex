#include <string>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y);

    int getmonth();

    int getday();

    int getyear();

    string toString();
};
