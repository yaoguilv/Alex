#ifndef BINARYSEARCHST_H
#define BINARYSEARCHST_H
#include "util/Comparable.h"

template <class Key, class Value>
class BinarySearchST {
private:
    Key * keys;
    Value * vals;
    int N = 0;
public:
    BinarySearchST(int capacity)
    {
        keys = new Key[capacity];
        vals = new Value[capacity];
    }

    int size()
    {
        return N;
    }

    bool isEmpty()
    {
        return 0 == N;
    }

    Value get(Key key)
    {
        if(isEmpty()) return nullptr;
        int i = rank(key);
        if(i < N && keys[i]->compareTo(key) == 0)
            return vals[i];
        else
            return nullptr;
    }

    int rank(Key key)
    {
        int lo = 0, hi = N - 1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int cmp = key->compareTo(keys[mid]);
            if(cmp < 0)
                hi = mid - 1;
            else if(cmp > 0)
                lo = mid + 1;
            else
                return mid;
        }
        return lo;
    }

    void put(Key key, Value val)
    {
        // Search for key. Update value if found; grow table if new.
        int i = rank(key);
        if(i < N && keys[i]->compareTo(key) == 0)
        {
            vals[i] = val;
            return;
        }
        for(int j = N; j > i; j--)
        {
            keys[j] = keys[j - 1];
            vals[j] = vals[j - 1];
        }

        keys[i] = key;
        vals[i] = val;
        N++;
    }

    Key min()
    {
        return keys[0];
    }

    Key max()
    {
        return keys[N - 1];
    }

    Key select(int k)
    {
        return keys[k];
    }

    Key ceiling(Key key)
    {
        int i = rank(key);
        return keys[i];
    }
};
#endif
