#ifndef MAXPQ_H
#define MAXPQ_H
#include "util/Comparable.h"

class MaxPQ {
    private:
        // heap-ordered complete binary tree.
        Comparable ** pq;
        // in pq[1..N] with pq[0] unused
        int N = 0;

        bool less(int i, int j);
        void exch(int i, int j);
        void swim(int k);
        void sink(int k);
    public:
        MaxPQ(int maxN);
        bool isEmpty();
        int size();
        void insert(Comparable * v);
        Comparable * delMax();
};
#endif
