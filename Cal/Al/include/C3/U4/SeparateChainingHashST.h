#ifndef SEPARATECHAININGHASHST_H
#define SEPARATECHAININGHASHST_H
#include "C3/U1/SequentialSearchST.h"

template<typename Key, typename Value>
class SeparateChainingHashST {
    private:
        // number of key-value pairs
        int N;
        // hash table size
        int M;
        // array of ST objects
        SequentialSearchST<Key, Value> ** st;

        int hash(Key key)
        {
            // waiting to translate java code: (key.hashCode() & 0x7fffffff) % M;
            return key->hashCode() % this->M;
        }

    public:
        SeparateChainingHashST(int inM = 997) : M(inM)
        {
            // Create M linked lists;
            st = new SequentialSearchST<Key, Value>*[M];
            for(int i = 0; i < M; i++)
                st[i] = new SequentialSearchST<Key, Value>();
        }

        Value get(Key key)
        {
            return st[hash(key)]->get(key);
        }

        void put(Key key, Value val)
        {
            st[hash(key)]->put(key, val);
        }
};
#endif
