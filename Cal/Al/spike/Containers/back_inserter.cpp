#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> foo, bar;
    for(int i=1; i<=5; i++)
    {
        foo.push_back(i);
        bar.push_back(i*10);
    }

    // iterator is like pointer
    // back_inserter generate an open pointer for insert
    std::copy(bar.begin(),bar.end(),back_inserter(foo));

    std::cout << "foo contains: ";
    for(std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    return 0;
}
