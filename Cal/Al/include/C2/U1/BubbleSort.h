#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "util/Comparable.h"


class BubbleSort {
public:
    static void sort(Comparable ** a, int arrLen);
    static bool isSorted(Comparable ** a, int arrLength);
private:
    static void exch(Comparable ** a, int i, int j);
    static bool less(Comparable * v, Comparable * w);

};
#endif
