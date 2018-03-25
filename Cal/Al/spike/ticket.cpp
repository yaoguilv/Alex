#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char ** argv)
{
    vector<int> foo(3);
    int myArr[] = {1, 2, 3};
    copy(myArr, myArr + 3, foo.begin());
    for(vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
    {
        cout << *it << "  ";
    }

    cout << endl;
    return 0;
}
