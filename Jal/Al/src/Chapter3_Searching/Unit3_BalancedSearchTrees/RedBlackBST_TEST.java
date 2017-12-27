package Chapter3_Searching.Unit3_BalancedSearchTrees;

import java.util.Comparator;

public class RedBlackBST_TEST<Key extends Comparable<Key>, Value>
{
    private static final boolean RED = true;
    private static final boolean BLACK = false;

    private class Node
    {
        Key key;
        Value val;
        Node left, right;
        int N;
        boolean color;

        Node(Key key, Value val, int N, boolean color)
        {
            this.key = key;
            this.val = val;
            this.N = N;
            this.color = color;
        }
    };

    private int size(Node h)
    {
        if(null == h)
            return 0;
        return h.N;
    }

    private boolean isRed(Node x)
    {
        if(x == null) return false;
        return x.color == RED;
    }

    Node rotateLeft(Node h)
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

    Node rotateRight(Node h)
    {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        x.N = h.N;
        h.N = 1 + size(h.left) + size(h.right);
        return x;
    }

    private Node root;

    private void flipColors(Node h)
    {
        h.color = RED;
        h.left.color = BLACK;
        h.right.color = BLACK;
    }

    public void put(Key key, Value val)
    {
        root = put(root, key, val);
        root.color = BLACK;
    }

    private Node put(Node h, Key key, Value val)
    {
        if(h == null)
            return new Node(key, val, 1, RED);

        int cmp = key.compareTo(h.key);
        if(cmp < 0) h.left = put(h.left, key, val);
        else if(cmp > 0) h.right = put(h.right, key, val);
        else h.val = val;

        if(isRed(h.right) && !isRed(h.left)) h = rotateLeft(h);
        if(isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
        if(isRed(h.left) && isRed(h.right)) flipColors(h);

        h.N = size(h.left) + size(h.right) + 1;
        return h;
    }

    public Value find(Key key)
    {
        return find(root, key);
    }

    public Value find(Node h, Key key)
    {
        System.out.print("find once \n");
        if(h == null)
            return null;

        int cmp = key.compareTo(h.key);
        if(cmp < 0) return find(h.left, key);
        else if(cmp > 0) return find(h.right, key);
        else return h.val;
    }

    public static void main(String[] args) {
        RedBlackBST_TEST<Integer, Integer> rb = new RedBlackBST_TEST<Integer, Integer>();
        int[] arr = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

        for (int i = 0; i < arr.length; i++) {
            rb.put(i + 1, arr[i]);
        }

        int key;
        System.out.print("please input the key to find(enter 0 to end):\n");

        key = StdLib.StdIn.readInt();
        while(0 != key) {
            System.out.print("the value and depth of key ");
            System.out.print(key);
            System.out.print(" is: ");
            System.out.print(rb.find(key));
            System.out.print("\n");
            System.out.print("please input the key to find(enter 0 to end):\n");
            key = StdLib.StdIn.readInt();
        }
    }

}
