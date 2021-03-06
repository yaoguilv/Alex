#ifndef SEQUENTIALSEARCHST_H
#define SEQUENTIALSEARCHST_H
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <class Key, class Value>
class SequentialSearchST {
private:
    class Node
    {
        // linked-list node
    public:
        Key key;
        Value val;
        Node * next;
        Node(Key key, Value val, Node * next)
        {
            this->key = key;
            this->val = val;
            this->next = next;
        }
    };
    Node * first = nullptr;

public:
    Value get(Key key)
    {
        // Search for key, return associated value.
        for(Node * x = first; x != nullptr; x = x->next)
            if(key->compareTo(x->key) == 0)
                // search hit
                return x->val;
        // search miss
        return nullptr;
    }

    void put(Key key, Value val)
    {
        // Search for key, Update value if found; grow table if new.
        for(Node * x = first; x != nullptr; x = x->next)
            if(key->compareTo(x->key) == 0)
                // Search hit: update val.
            {
                x->val = val;
                return;
            }
        // Search miss: add new node.
        first = new Node(key, val, first);
    }

    int size()
    {
        int arrSize = 0;
        for(Node * x = first; x != nullptr; x = x->next)
            arrSize++;
        return arrSize;

    }

    bool contains(Key key)
    {
        for(Node * x = first; x != nullptr; x = x->next)
            if(key->compareTo(x->key) == 0)
                return true;
        return false;
    }

    void getKeys(vector<Key>& keyArr)
    {
        int arrSize = size();
        int n = 0;
        for(Node * x = first; x != nullptr; x = x->next)
        {
            keyArr.push_back(x->key);
            n++;
        }
    }
};
#endif
