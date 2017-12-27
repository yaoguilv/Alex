#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

int main() {
    using namespace std;
    string sentence = "And I feel fine...";
    istringstream iss(sentence);
    istream_iterator<string> eos;
    istream_iterator<string> iit_iss(iss);
    ostream_iterator<string> oit(cout, "\n");
    copy(iit_iss, eos, oit);
}
