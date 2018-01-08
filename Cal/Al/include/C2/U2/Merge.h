#ifndef MERGE_H
#define MERGE_H
#include "util/Comparable.h"

class Merge {
public:
    void sort(Comparable ** a, int arrLen);
    static bool isSorted(Comparable ** a, int arrLength);
private:
    Comparable ** aux;
    void sort(Comparable ** a, int lo, int hi);
    void merge(Comparable ** a, int lo, int mid, int hi);
    static void exch(Comparable ** a, int i, int j);
    static bool less(Comparable * v, Comparable * w);
};
#endif
