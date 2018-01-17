package C3.U2;

import java.util.*;

public class BST<Key extends Comparable<Key>, Value> {
    // root of BST
    private Node root;

    private class Node
    {
        // key
        private Key key;
        // associated value
        private Value val;
        // links to subtrees
        private Node left, right;
        // # nodes in subtree rooted here
        private int N;

        public Node(Key key, Value val, int N)
        {
            this.key = key;
            this.val = val;
            this.N = N;
        }
    }

    public int size()
    {
        return size(root);
    }

    private int size(Node x)
    {
        if(null == x)
            return 0;
        else
            return x.N;
    }

    public Value get(Key key)
    {
        return get(root, key);
    }

    private Value get(Node x, Key key)
    {
        // Return value associated with key in the subtree rooted at x;
        // return null if key not present in subtree rooted at x.
        if(x == null) return null;
        int cmp = key.compareTo(x.key);
        if(cmp < 0)
            return get(x.left, key);
        else if(cmp > 0)
            return get(x.right, key);
        else
            return x.val;
    }

    public void put(Key key, Value val)
    {
        // Search for key. Update value if found; grow table if new.
        root = put(root, key, val);
    }

    private Node put(Node x, Key key, Value val)
    {
        // Change key's value to val if key in subtree rooted at x.
        // Otherwise, add new node to subtree associating key with val.
        if(null == x)
            return new Node(key, val, 1);
        int cmp = key.compareTo(x.key);
        if(cmp < 0)
            x.left = put(x.left, key, val);
        else if(cmp > 0)
            x.right = put(x.right, key, val);
        else
            x.val = val;
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    public Key min()
    {
        return min(root).key;
    }

    private Node min(Node x)
    {
        if(x.left == null)
            return x;
        return min(x.left);
    }

    public Key max()
    {
        return max(root).key;
    }

    private Node max(Node x)
    {
        if(x.right == null)
            return x;
        return max(x.right);
    }


    public Key floor(Key key)
    {
        Node x = floor(root, key);
        if(null == x)
            return null;
        return x.key;
    }

    private Node floor(Node x, Key key)
    {
        if(x == null)
            return null;
        int cmp = key.compareTo(x.key);
        if(0 == cmp)
            return x;
        if(cmp < 0)
            return floor(x.left, key);
        Node t = floor(x.right, key);
        if(null != t)
            return t;
        else
            return x;
    }

    public Key select(int k)
    {
        return select(root, k).key;
    }

    private Node select(Node x, int k)
    {
        // Return Node containing key of rank k.
        if(null == x)
            return null;
        int t = size(x.left);
        if(t > k)
            return select(x.left, k);
        else if(t < k)
            return select(x.right, k - t - 1);
        else
            return x;
    }

    public int rank(Key key)
    {
        return rank(key, root);
    }

    private int rank(Key key, Node x)
    {
        // Return number of keys less than x.key in the subtree rooted at x.
        if(null == x)
            return 0;
        int cmp = key.compareTo(x.key);
        if(cmp < 0)
            return rank(key, x.left);
        else if(cmp > 0)
            return 1 + size(x.left) + rank(key, x.right);
        else
            return size(x.left);
    }

    public void deleteMin()
    {
        root = deleteMin(root);
    }

    private Node deleteMin(Node x)
    {
        if(x.left == null)
            return x.right;
        x.left = deleteMin(x.left);
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    public void delete(Key key)
    {
        root = delete(root, key);
    }

    private Node delete(Node x, Key key)
    {
        if(null == x)
            return null;
        int cmp = key.compareTo(x.key);
        if(cmp < 0)
            x.left = delete(x.left, key);
        else if(cmp > 0)
            x.right = delete(x.right, key);
        else
        {
            if(x.right == null)
                return x.left;
            if(x.left == null)
                return x.right;
            Node t = x;
            x = min(t.right);
            x.right = deleteMin(t.right);
            x.left = t.left;
        }
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    public void print()
    {
        print(root);
    }

    private void print(Node x)
    {
        if(null == x)
            return;
        print(x.left);
        StdLib.StdOut.println(x.key);
        print(x.right);
    }

    public Iterable<Key> keys()
    {
        return keys(min(), max());
    }

    public Iterable<Key> keys(Key lo, Key hi)
    {
        Queue<Key> queue = new LinkedList<Key>();
        keys(root, queue, lo, hi);
        return queue;
    }

    private void keys(Node x, Queue<Key> queue, Key lo, Key hi)
    {
        if(null == x)
            return;
        int cmplo = lo.compareTo(x.key);
        int cmphi = hi.compareTo(x.key);
        if(cmplo < 0)
            keys(x.left, queue, lo, hi);
        if(cmplo <= 0 && cmphi >= 0)
            queue.add(x.key);
        if(cmphi > 0)
            keys(x.right, queue, lo, hi);
    }

    public static void main(String[] args)
    {
        BST<Integer, String> myBST = new BST<Integer, String>();

        System.out.println("now size:");
        System.out.println(myBST.size());

        myBST.put(1, "aaa");
        myBST.put(3, "ccc");
        myBST.put(2, "bbb");

        System.out.println("now size:");
        System.out.println(myBST.size());

        System.out.println("key 2's value is:");
        System.out.println(myBST.get(2));

        System.out.println("min key:");
        System.out.println(myBST.min());

        System.out.println("floor of 2 is:");
        System.out.println(myBST.floor(2));

        System.out.println("select 2 :");
        System.out.println(myBST.select(2));

        System.out.println("rank of 3 is:");
        System.out.println(myBST.rank(3));

        System.out.println("print all Node:");
        myBST.print();

        Iterable<Integer> myIterable = myBST.keys();
        Iterator<Integer> myIt = myIterable.iterator();
        System.out.println("now Iterable the tree：");
        while(myIt.hasNext())
        {
            System.out.println(myIt.next());
        }

        System.out.println("now delete min:");
        myBST.deleteMin();
        myBST.print();


        System.out.println("now delete 2:");
        myBST.delete(2);
        myBST.print();


    }

}

