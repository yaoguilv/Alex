#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int a[3] = {1,2,3};
    for(auto it = begin(a); it < end(a); it++)
    {
        cout << *it << endl;
    }

    int length = end(a) - begin(a);
    cout << length << endl;

    int* b = a;
    cout << *b << endl;

    length = end(b) - begin(b);
    cout << length << endl;
}
