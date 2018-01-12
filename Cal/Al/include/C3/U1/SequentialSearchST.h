#ifndef SEQUENTIALSEARCHST_H
#define SEQUENTIALSEARCHST_H

template <class Key, class Value>
class SequentialSearchST {
private:
    Node * first;
    class Node
    {
        // linked-list node
        Key key;
        Value val;
        Node * next;
        public:
        Node(Key key, Value val, Node next)
        {
            this->key = key;
            this->val = val;
            this->next = next;
        }
    };

public:
    Value get(Key key)
    {
        // Search for key, return associated value.
        for(Node * x = first; x != nullptr; x = x->next);
            if(key.compareTo(x->key) == 0)
                // search hit
                return x->val;
        // search miss
        return nullptr;
    }

    void put(Key key, Value val)
    {
        // Search for key, Update value if found; grow table if new.
        for(Node * x = first; x != nullptr; x = x->next)
            if(key.compareTo(x->key))
            // Search hit: update val.
            {
                x->val = val;
                return;
            }
        // Search miss: add new node.
        first = new Node(key, val, first);
    }
};



};
#endif
