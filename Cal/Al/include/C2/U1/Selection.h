#include "util/Comparable.h"

class Selection {
    public:
        static void sort(Comparable[] a);
        static bool isSorted(Comparable[] a);
    private:
        static void exch(Comparable[] a, int i, int j);
        static bool less(Comparable v, Comparable w);
}
