#include <iostream>
#include <algorithm>
#include <vector>

#include "Chapter1_Fundamentals/Unit1_BasicProgrammingModel/BinarySearch.h"

using namespace std;

int main()
{
    vector<int> whitelist = {2, 1, 5, 4, 3};

    sort(whitelist.begin(), whitelist.end());

    cout << "please enter a int to find(enter 0 to exit):" << endl;

    int key;
    cin >> key;
    while(0 != key)
    {
        // Read key, print if not in whitelist.
        if(BinarySearch::rank(key, whitelist) > 0)
            cout << "found" << endl;
        else
            cout << "not found" << endl;
        cin >> key;
    }
    return 0;
}
