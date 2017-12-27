#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace StdLib {
class StdIn {
public:
    static std::string readAll() {
        std::string mystr;
        getline(std::cin, mystr);

        return mystr;
    }

    // Read rest of input as array of strings
    static std::vector<std::string> readStrings() {
        std::string inputString = StdIn::readAll();
        std::istringstream iss(inputString);
        std::istream_iterator<std::string> ist(iss);
        std::istream_iterator<std::string> eos;
        std::vector<std::string> fields;
        std::copy(ist, eos, std::back_inserter(fields));
        // above two scentences can be replaced by the scentences below
        // but the next two lines can only receive limited values
        /* std::vector<std::string> fields(2); */
        /* std::copy(ist, eos, fields.begin()); */

        return fields;
    }

};
}
int main()
{
    std::cout << "Hello ticket!" << std::endl;

    std::vector<std::string> fields = StdLib::StdIn::readStrings();
    for(std::vector<std::string>::iterator it = fields.begin(); it != fields.end(); it++) {
        std::cout << *it << std::endl;
    }
    return 0;

}
