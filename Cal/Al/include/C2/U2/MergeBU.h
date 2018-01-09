#ifndef MERGEBU_H
#define MERGEBU_H
#include "util/Comparable.h"

class MergeBU {
    public:
        static void sort(Comparable ** a, int arrLen);
        static bool isSorted(Comparable ** a, int arrLen);
    private:
        static Comparable ** aux;
        static void merge(Comparable ** a, int lo, int mid, int hi);
        static void exch(Comparable ** a, int i, int j);
        static bool less(Comparable * v, Comparable * w);
};
#endif
