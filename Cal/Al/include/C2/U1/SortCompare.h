#ifndef SORTCOMPARE_H
#define SORTCOMPARE_H
#include <string>

using namespace std;

class SortCompare {
public:
    static double time(string alg, CDouble ** a, int arrLen);
    static double timeRandomInput(string alg, int N, int T);
};
#endif
