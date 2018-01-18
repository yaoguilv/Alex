package C3.U4;
import C3.U1.SequentialSearchST;

public class SeparateChainingHashST<Key extends Comparable<Key>, Value> {
    // number of key-value pairs
    private int N;
    // hash table size
    private int M;
    // array of ST objects
    private SequentialSearchST<Key, Value>[] st;

    public SeparateChainingHashST()
    {
        this(997);
    }

    @SuppressWarnings("unchecked")
    public SeparateChainingHashST(int M)
    {
        // Create M linked lists.
        this.M = M;
        st = (SequentialSearchST<Key, Value>[]) new SequentialSearchST<?, ?>[M];
        for(int i = 0; i < M; i++)
            st[i] = new SequentialSearchST<Key, Value>();
    }

    private int hash(Key key)
    {
        return (key.hashCode() & 0x7fffffff) % M;
    }

    @SuppressWarnings("cast")
    public Value get(Key key)
    {
        return (Value)st[hash(key)].get(key);
    }

    public void put(Key key, Value val)
    {
        st[hash(key)].put(key, val);
    }
}
