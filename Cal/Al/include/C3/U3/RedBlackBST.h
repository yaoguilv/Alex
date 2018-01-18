#ifndef REDBLACKBST_H
#define REDBLACKBST_H
template <class Key, class Value>
class RedBlackBST {
    private:
        static const bool RED = true;
        static const bool BLACK = false;
        class Node
        {
            public:
            // key
            Key key;
            // associated data
            Value val;
            // subtrees
            Node * left;
            Node * right;
            // # nodes in this subtree
            int N;
            // color of link from parent to this node
            bool color;

            Node(Key key, Value val, int N, bool color)
            {
                this->key = key;
                this->val = val;
                this->N = N;
                this->color = color;
            }
        };
        Node * root;

        bool isRed(Node * x)
        {
            if(nullptr == x)
                return false;
            return RED == x->color;
        }

        Node * rotateLeft(Node * h)
        {
            Node * x = h->right;
            h->right = x->left;
            x->left = h;
            x->color = h->color;
            h->color = RED;
            x->N = h->N;
            h->N = 1 + size(h->left) + size(h->right);
            return x;
        }

        Node * rotateRight(Node * h)
        {
            Node * x = h->left;
            h->left = x->right;
            x->right = h;
            x->color = RED;
            x->N = h->N;
            h->N = 1 + size(h->left) + size(h->right);
            return x;
        }

        void flipColors(Node * h)
        {
            h->color = RED;
            h->left->color = BLACK;
            h->right->color = BLACK;
        }

        int size(Node * x)
        {
            if(nullptr == x)
                return 0;
            else
                return x->N;
        }

        Node * put(Node * h, Key key, Value val)
        {
            // Do standard insert, with red link to parent.
            if(nullptr == h)
                return new Node(key, val, 1, RED);
            int cmp = key->compareTo(h->key);
            if(cmp < 0)
                h->left = put(h->left, key, val);
            else if(cmp > 0)
                h->right = put(h->right, key, val);
            else
                h->val = val;
            if(isRed(h->right) && !isRed(h->left))
                h = rotateLeft(h);
            if(isRed(h->left) && isRed(h->left->left))
                h = rotateRight(h);
            if(isRed(h->left) && isRed(h->right))
                flipColors(h);

            h->N = size(h->left) + size(h->right) + 1;
            return h;
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
            else if(cmp > 0)
                return get(x->right, key);
            else
                return x->val;
        }
    public:
        int size()
        {
            return size(root);
        }

        void put(Key key, Value val)
        {
            // Search for key. Update value if found; grow table if new.
            root = put(root, key, val);
            root->color = BLACK;
        }

        Value get(Key key)
        {
            return get(root, key);
        }
};
#endif
