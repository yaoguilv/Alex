#include <iostream>
#include "C2/U1/Selection.h"

using namespace std;

int main()
{
    cout << "Hello tester!" << endl;
        Date[] dat = new Date[]{new Date(1, 1, 2010),
        new Date(1, 1, 2017), new Date(1, 1, 2015)};
        Selection.sort(dat);
        for(int i = 0; i < 3; i++)
        {
            System.out.println(dat[i]);
        }

}
