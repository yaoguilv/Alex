#include "util/Comparable.h"

class Selection {
    public:
        static void sort(Comparable ** a, int arrLength);
        static bool isSorted(Comparable ** a, int arrLength);
    private:
        static void exch(Comparable ** a, int i, int j);
        static bool less(Comparable * v, Comparable * w);
};
