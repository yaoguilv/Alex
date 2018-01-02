#include <iostream>
#include "C2/U2/ClientConnection.h"
using namespace std;

int main()
{
    cout << 1000 << endl;
    ClientConnection htx("htx", 3);
    cout << htx.getNum() << endl;
    return 0;
}
