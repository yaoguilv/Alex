#include <array>
#include <vector>
#include "Chapter1_Fundamentals/Unit1_BasicProgrammingModel/BinarySearch.h"

using namespace std;

int BinarySearch::rank(int key, vector<int> a)
{
    int lo = 0;
    int hi = a.size()- 1;
    while(lo <= hi)
    {
        //Key is in a[lo..hi] or not present;
        int mid = lo + (hi - lo) / 2;
        if(key < a[mid])
            hi = mid - 1;
        else if(key > a[mid])
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}
