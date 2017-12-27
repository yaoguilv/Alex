#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "StdLib.h"

namespace StdLib {
std::string StdIn::readAll() {
    std::string mystr;
    getline(std::cin, mystr);

    return mystr;

}

std::vector<std::string> StdIn::readStrings() {
    std::string inputString = StdIn::readAll();
    std::istringstream iss(inputString);
    std::istream_iterator<std::string> ist(iss);
    std::istream_iterator<std::string> eos;
    std::vector<std::string> fields;
    std::copy(ist, eos, std::back_inserter(fields));

    return fields;
}
}

