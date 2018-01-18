#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <class Key, class Value>
class BST {
private:
    class Node
    {
    public:
        // key
        Key key;
        // associated value
        Value val;
        // links to subtrees
        Node * left;
        Node * right;
        // # nodes in subtree rooted here
        int N;
        Node(Key key, Value val, int N)
        {
            this->key = key;
            this->val = val;
            this->N = N;
        }
    };
    // root of BST
    Node * root;

    int size(Node * x)
    {
        if(nullptr == x)
            return 0;
        else
            return x->N;

    }

    Value get(Node * x, Key key)
    {
        // Return value associated with key int the subtree rooted at x;
        // return null if key not present in subtree rooted at x.
        if(nullptr == x)
            return nullptr;
        int cmp = key->compareTo(x->key);
        if(cmp < 0)
            return get(x->left, key);
        else if (cmp > 0)
            return get(x->right, key);
        else
            return x->val;
    }

    Node * put(Node * x, Key key, Value val)
    {
        // Change key's value to val if key in subtree rooted at x.
        // Otherwise, add new node to subtree associating key with val.
        if(nullptr == x)
            return new Node(key, val, 1);
        int cmp = key->compareTo(x->key);
        if(cmp < 0)
            x->left = put(x->left, key, val);
        else if(cmp > 0)
            x->right = put(x->right, key, val);
        else
            x->val = val;
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node * min(Node * x)
    {
        if(x->left == nullptr)
            return x;
        return min(x->left);
    }

    Node * max(Node * x)
    {
        if(x->right == nullptr)
            return x;
        return max(x->right);
    }

    Node * floor(Node * x, Key key)
    {
        if(nullptr == x)
            return nullptr;
        int cmp = key->compareTo(x->key);
        if(0 == cmp)
            return x;
        if(cmp < 0)
            return floor(x->left, key);
        Node * t = floor(x->right, key);
        if(nullptr != t)
            return t;
        else
            return x;
    }

    Node * select(Node * x, int k)
    {
        // Return Node containing key of rank k.
        if(nullptr == x)
            return nullptr;
        int t = size(x->left);
        if(t > k)
            return select(x->left, k);
        else if(t < k)
            return select(x->right, k - t - 1);
        else
            return x;
    }

    int rank(Key key, Node * x)
    {
        // Return number of keys less than x.key in the subtree rooted at x.
        if(nullptr == x)
            return 0;
        int cmp = key->compareTo(x->key);
        if(cmp < 0)
            return rank(key, x->left);
        else if(cmp > 0)
            return 1 + size(x->left) + rank(key, x->right);
        else
            return size(x->left);
    }

    Node * deleteMin(Node * x)
    {
        if(x->left == nullptr)
            return x->right;
        x->left = deleteMin(x->left);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node * deleteNode(Node * x, Key key)
    {
        if(nullptr == x)
            return nullptr;
        int cmp = key->compareTo(x->key);
        if(cmp < 0)
            x->left = deleteNode(x->left, key);
        else if(cmp > 0)
            x->right = deleteNode(x->right, key);
        else
        {
            if(x->right == nullptr)
                return x->left;
            if(x->left == nullptr)
                return x->right;
            Node * t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    void print(Node * x)
    {
        if(nullptr == x)
            return;
        print(x->left);
        cout << x->key->toString() << "    " << x->val << endl;
        print(x->right);
    }


public:
    int size()
    {
        return size(root);
    }

    Value get(Key key)
    {
        return get(root, key);
    }

    void put(Key key, Value val)
    {
        // Search for key. Update value if found; grow table if new.
        root = put(root, key, val);
    }

    Key min()
    {
        return min(root)->key;
    }

    Key * max()
    {
        return max(root)->key;
    }

    Key floor(Key key)
    {
        Node * x = floor(root, key);
        if(nullptr == x)
            return nullptr;
        return x->key;
    }

    Key select(int k)
    {
        return select(root, k)->key;
    }

    int rank(Key key)
    {
        return rank(key, root);
    }

    void deleteMin()
    {
        root = deleteMin(root);
    }

    void deleteKey(Key key)
    {
        root = deleteNode(root, key);
    }

    void print()
    {
        print(root);
    }


    /* public Iterable<Key> keys() */
    /* { */
    /*     return keys(min(), max()); */
    /* } */

    /* public Iterable<Key> keys(Key lo, Key hi) */
    /* { */
    /*     Queue<Key> queue = new LinkedList<Key>(); */
    /*     keys(root, queue, lo, hi); */
    /*     return queue; */
    /* } */

    /* private void keys(Node x, Queue<Key> queue, Key lo, Key hi) */
    /* { */
    /*     if(null == x) */
    /*         return; */
    /*     int cmplo = lo.compareTo(x.key); */
    /*     int cmphi = hi.compareTo(x.key); */
    /*     if(cmplo < 0) */
    /*         keys(x.left, queue, lo, hi); */
    /*     if(cmplo <= 0 && cmphi >= 0) */
    /*         queue.add(x.key); */
    /*     if(cmphi > 0) */
    /*         keys(x.right, queue, lo, hi); */
    /* } */
};
#endif
