#include <iostream>

using namespace std;

// execute command: bin/ticket dd
int main(int argc, char ** argv)
{
    // argv[0] is the program name("ticket")
    char * a = argv[1];
    string b = a;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
