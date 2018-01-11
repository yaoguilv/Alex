#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "util/Comparable.h"

class Heapsort {
public:
    static void sort(Comparable ** a, int arrLen);
private:
    static void sink(Comparable ** a, int k, int N);
    static bool less(Comparable ** a, int i, int j);
    static void exch(Comparable ** a, int i, int j);
};
#endif
