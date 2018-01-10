#ifndef QUICK3WAY_H
#define QUICK3WAY_H
#include "util/Comparable.h"

class Quick3way {
public:
    static void sort(Comparable ** a, int arrLen);
    static bool isSorted(Comparable ** a, int arrLength);

private:
    static void sort(Comparable ** a, int lo, int hi);
    static int partition(Comparable ** a, int lo, int hi);
    static void exch(Comparable ** a, int i, int j);
    static bool less(Comparable * v, Comparable * w);
};
#endif
