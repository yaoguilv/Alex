package C3.U3;

public class RedBlackBST {
    private static final boolean RED = true;
    private static final boolean BLACK = false;

    private Node root;

    // BST node with color bit
    private class Node
    {
        // key
        Key key;
        // associated data
        Value val;
        // subtrees
        Node left, right;
        // # nodes in this subtree
        int N;
        // color of link from parent to this node
        boolean color;

        Node(Key key, Value val, int N, boolean color)
        {
            this.key = key;
            this.val = val;
            this.N = N;
            this.color = color;
        }
    }

    private boolean isRed(Node x)
    {
        if(null == x)
            return false;
        return RED == x.color;
    }

    private Node rotateLeft(Node h)
    {
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        x.N = h.N;
        h.N = 1 + size(h.left) + size(h.right);

        return x;
    }

    private Node rotateRight(Node h)
    {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = RED;
        x.N = h.N;
        h.N = 1 + size(h.left) + size(h.right);
        return x;
    }

    private void flipColors(Node h)
    {
        h.color = RED;
        h.left.color = BLACK;
        h.right.color = BLACK;
    }

    public int size()
    {
        return size(root);
    }

    private size(Node x)
    {
        if(null == x)
            return 0;
        else
            return x.N;
    }

    public void put(Key key, Value val)
    {
        // Search for key. Update value if found; grow table if new.
        root = put(root, key, val);
        root.color = BLACK;
    }

    private Node put(Node h, Key key, Value val)
    {
        // Do standard insert, with red link to parent.
        if(null == h)
            return new Node(key, val, 1, RED);
        int cmp = key.compareTo(h.key);
        if(cmp < 0)
            h.left = put(h.left, key, val);
        else if(cmp > 0)
            h.right = put(h.right, key, val);
        else
            h.val = val;

        if(isRed(h.right) && !isRed(h.left))
            h = rotateLeft(h);
        if(isRed(h.left) && isRed(h.left.left))
            h= rotateRight(h);
        if(isRed(h.left) && isRed(h.right))
            flipColors(h);

        h.N = size(h.left) + size(h.right) + 1;
        return h;
    }
}
