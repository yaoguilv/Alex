#ifndef MINPQ_H
#define MINPQ_H

#include "util/Comparable.h"

class MinPQ {
    private:
        // heap-ordered complete binary tree.
        Comparable ** pq;
        // in pq[1..N] with pq[0] unused
        int N = 0;

        bool greater(int i, int j);
        void exch(int i, int j);
        void swim(int k);
        void sink(int k);
    public:
        MinPQ(int minN);
        bool isEmpty();
        int size();
        void insert(Comparable * v);
        Comparable* delMin();
};
#endif
