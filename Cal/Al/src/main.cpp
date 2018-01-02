#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include "C2/U2/ClientConnection.h"
#include "StdLib.h"

using namespace std;

int main()
{
    cout << 1000 << endl;
    /* ClientConnection htx("htx", 3); */
    /* cout << htx.getNum() << endl; */

    std::vector<std::string> fields = StdLib::StdIn::readStrings();
    for(std::vector<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
        std::cout << *it << std::endl;
    }

    int b = StdLib::MyMath::myAdd(1, 6);
    std::cout << "result is " << b << std::endl;
    return 0;
}
