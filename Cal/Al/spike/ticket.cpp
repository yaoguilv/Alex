#include <iostream>

using namespace std;

// execute command: bin/ticket dd
int main(int argc, char ** argv)
{
    int ** arrA;
    int arrB[3];
    for(int i = 1; i < 4; i++)
    {
        arrB[i - 1] = i * 10;
    }

    int * arrC[3];
    for(int i = 0; i < 3; i++)
    {
        arrC[i] = arrB + i;
    }

    cout << "int * arrC:" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << arrC[i] << endl;
    }

    arrA = arrC;
    cout << "int ** arrA:" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << arrA[i] << endl;
    }

    return 0;
}
