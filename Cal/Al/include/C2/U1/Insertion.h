#ifndef INSERTION_H
#define INSERTION_H

#include "util/Comparable.h"

class Insertion {
public:
    static void sort(Comparable ** a, int arrLen);
private:
    static void exch(Comparable ** a, int i, int j);
    static bool less(Comparable * v, Comparable * w);
    static bool isSorteed(Comparable ** a, int arrLen);
};
#endif
