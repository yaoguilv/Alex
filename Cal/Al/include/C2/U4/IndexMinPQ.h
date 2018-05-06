#ifndef INDEXMINPQ_H
#define INDEXMINPQ_H

#include "util/Comparable.h"

class IndexMinPQ {
private:
    // number of elements on PQ
    int N;
    // binary heap using 1-based indexing
    vector<int> pq;
    vector<Comparable*> keys;

    swim(int k);

    sink(int k);

public:
    bool isEmpty();

    bool contains(int k);

    int size();

    void insert(int k, Comparable* key);

    int min();

    Comparable* minKey();

    int delMin();

    void change(int k, Comparable* key);

    void decrease(int k, Comparable* key);

    void increase(int k, Comparable* key);
};
#endif
