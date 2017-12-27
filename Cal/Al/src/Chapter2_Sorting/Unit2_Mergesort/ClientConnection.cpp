#include "Chapter2_Sorting/Unit2_Mergesort/ClientConnection.h"

ClientConnection::ClientConnection(string s, int n)
{
    name = s;
    num = n;
}

int ClientConnection::getNum()
{
    return num + 1;
}
