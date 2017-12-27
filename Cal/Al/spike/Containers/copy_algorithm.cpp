#include <iostream>
#include <algorithm>
#include <vector>

// copy function is just like:
/* template<class InputIterator, class OutputIterator> */
/*   OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result) */
/* { */
/*   while (first!=last) { */
/*     *result = *first; */
/*     ++result; ++first; */
/*   } */
/*   return result; */
/* } */

int main()
{
    int myints[] = {10, 20, 30, 40, 50, 60, 70};
    std::vector<int> myvector(7);

    // here is 7, not 6, like above(while(first!=last))
    std::copy(myints, myints+7, myvector.begin());

    std::cout << "myvector contains: ";
    for(std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << std::endl;

    return 0;
}

