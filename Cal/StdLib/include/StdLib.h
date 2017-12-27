#include <string>
#include <vector>

namespace StdLib {
class StdIn {
public:
    static std::string readAll();

    // Read rest of input as array of strings
    static std::vector<std::string> readStrings();
};

class MyMath {
public:
    static int myAdd(int a, int b);
};
}

