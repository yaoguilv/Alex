#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::ostringstream foo;
    foo.precision(4);
    foo.width(10);
    double N = 5.2345678;
    foo << N;
    std::cout << foo.str() << std::endl;
}
