package C3.U1;

import java.util.*;

public class SequentialSearchST<Key, Value> {
    // first node in the linked list
    private Node first;

    private class Node
    {
        // linked-list node
        Key key;
        Value val;
        Node next;
        public Node(Key key, Value val, Node next)
        {
            this.key = key;
            this.val = val;
            this.next = next;
        }
    }

    public Value get(Key key)
    {
        // Search for key, return associated value.
        for(Node x = first; x != null; x = x.next)
            if(key.equals(x.key))
                // search hit
                return x.val;
        // search miss
        return null;
    }

    public void put(Key key, Value val)
    {
        // Search for key, Update value if found; grow table if new.
        for(Node x = first; x != null; x = x.next)
            if(key.equals(x.key))
                // Search hit: update val.
            {
                x.val = val;
                return;
            }
        // Search miss: add new node.
        first = new Node(key, val, first);
    }

    public int size()
    {
        int mySize = 0;
        for(Node x = first; x != null; x = x.next)
            mySize++;
        return mySize;

    }

    /**
      * Returns all keys in the symbol table as an {@code Iterable}.
      * To iterate over all of the keys in the symbol table named {@code st},
      * use the foreach notation: {@code for (Key key : st.keys())}.
      *
      * @return all keys in the symbol table
      */
    public Iterable<Key> keys()  {
        LinkedList<Key> queue = new LinkedList<Key>();
        for (Node x = first; x != null; x = x.next)
            queue.add(x.key);
        return queue;
    }

    /**
     * Returns true if this symbol table contains the specified key.
     *
     * @param  key the key
     * @return {@code true} if this symbol table contains {@code key};
     *         {@code false} otherwise
     * @throws IllegalArgumentException if {@code key} is {@code null}
     */
    public boolean contains(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to contains() is null");
        return get(key) != null;
    }



    public static void main(String[] args)
    {
        SequentialSearchST<Integer, String> myST = new SequentialSearchST<Integer, String>();
        myST.put(1, "dd");
        myST.put(3, "gg");
        myST.put(2, "gew");
        System.out.println(myST.get(2));
    }

}
