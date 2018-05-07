#ifndef INDEXMINPQ_H
#define INDEXMINPQ_H

#include <vector>
#include <iterator>

#include "util/Comparable.h"

using namespace std;

class IndexMinPQ {
private:
    // number of elements on PQ
    int N;
    // binary heap using 1-based indexing
    vector<int> pq;

    vector<int> qp;

    vector<Comparable*> keys;

    void swim(int k);

    void sink(int k);

    bool greater(int i, int j);

    void exch(int i, int j);

public:
    IndexMinPQ(int NMax);

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
