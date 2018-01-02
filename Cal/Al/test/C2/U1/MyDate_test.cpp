#include <iostream>
#include "C2/U1/MyDate.h"

using namespace std;

int main()
{
   MyDate darr[3] = {MyDate(1, 1, 2010),
   MyDate(1, 1, 2017),
   MyDate(1, 1, 2013)};
   for(int i = 0; i < 3; i++)
   {
       cout << darr[i].toString() << endl;
   }
}

