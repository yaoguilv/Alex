#include <iostream>
#include <sstream>

int main() {
    std::ostringstream foo;
    // ate means "at end"
    std::ostringstream bar(std::ostringstream::ate);

    foo.str("Test String");
    bar.str("Test String");

    foo << 101;
    bar << 101;

    std::cout << foo.str() << std::endl;
    std::cout << bar.str() << std::endl;

    return 0;
}
