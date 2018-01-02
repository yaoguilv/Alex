#include "C2/U2/ClientConnection.h"

ClientConnection::ClientConnection(string s, int n)
{
    name = s;
    num = n;
}

int ClientConnection::getNum()
{
    return num + 1;
}
