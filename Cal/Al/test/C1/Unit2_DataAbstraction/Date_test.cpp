#include <iostream>
#include "C1/U2/Date.h"

using namespace std;

int main()
{
    int m = 12;
    int d = 11;
    int y = 2017;

    Date* date = new Date(m, d, y);
    cout << date->toString() << endl;
}
