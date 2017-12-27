#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> myvector;
    for(int i = 1; i < 10; i++)
        myvector.push_back(i);

    // can set the delimiter
    std::ostream_iterator<int> out_it(std::cout, ", ");
    std::copy(myvector.begin(), myvector.end(), out_it);

    return 0;
}

