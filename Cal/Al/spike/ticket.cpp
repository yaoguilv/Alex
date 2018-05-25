#include <iostream>
#include <vector>
#include <iterator>
#include <limits>

using namespace std;

int main()
{
    cout << long(numeric_limits<char16_t>::max()) << endl;
    cout << numeric_limits<int>::max() << endl;
    return 0;
}
