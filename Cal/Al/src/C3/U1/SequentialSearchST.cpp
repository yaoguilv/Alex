#include "C3/U1/SequentialSearchST.h"
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

public static void main(String[] args)
{
    SequentialSearchST<Integer, String> myST = new SequentialSearchST<Integer, String>();
    myST.put(1, "dd");
    myST.put(3, "gg");
    myST.put(2, "gew");
    System.out.println(myST.get(2));
}

