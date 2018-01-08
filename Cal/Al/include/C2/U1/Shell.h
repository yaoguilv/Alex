#ifndef SHELL_H
#define SHELL_H
#include "util/Comparable.h"

class Shell {
public:
    static void sort(Comparable ** a, int arrLen);
    static bool isSorted(Comparable ** a, int arrLength);
private:
    static void exch(Comparable ** a, int i, int j);
    static bool less(Comparable * v, Comparable * w);
};
#endif
