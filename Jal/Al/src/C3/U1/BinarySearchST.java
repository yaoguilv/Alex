package C3.U1;

import java.util.*;

public class BinarySearchST<Key extends Comparable<Key>, Value>
{
    private Key[] keys;
    private Value[] vals;
    private int N;

    @SuppressWarnings("unchecked")
    public BinarySearchST(int capacity)
    {
        keys = (Key[]) new Comparable<?>[capacity];
        vals = (Value[]) new Comparable<?>[capacity];
    }

    public int size()
    {
        return N;
    }

    public boolean isEmpty()
    {
        return 0 == N;
    }

    public Value get(Key key)
    {
        if(isEmpty()) return null;
        int i = rank(key);
        if(i < N && keys[i].compareTo(key) == 0)
            return vals[i];
        else
            return null;
    }

    public int rank(Key key)
    {
        int lo = 0, hi = N - 1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int cmp = key.compareTo(keys[mid]);
            if(cmp < 0)
                hi = mid - 1;
            else if(cmp > 0)
                lo = mid + 1;
            else
                return mid;
        }
        return lo;
    }

    public void put(Key key, Value val)
    {
        // Search for key. Update value if found; grow table if new.
        int i = rank(key);
        if(i < N && keys[i].compareTo(key) == 0)
        {
            vals[i] = val;
            return;
        }
        for(int j = N; j > i; j--)
        {
            keys[j] = keys[j - 1];
            vals[j] = vals[j - 1];
        }

        keys[i] = key;
        vals[i] = val;
        N++;
    }

    public Key min()
    {
        return keys[0];
    }

    public Key max()
    {
        return keys[N - 1];
    }

    public Key select(int k)
    {
        return keys[k];
    }

    public Key ceiling(Key key)
    {
        int i = rank(key);
        return keys[i];
    }

    public Iterable<Key> keys(Key lo, Key hi)
    {
        Queue<Key> q = new LinkedList<Key>();
        for(int i = rank(lo); i < rank(hi); i++)
            q.add(keys[i]);
        if(contain(hi))
            q.add(keys[rank(hi)]);
        return q;
    }

    private boolean contain(Key key)
    {
        if(keys[rank(key)] == key)
            return true;
        else
            return false;
    }

    public static void main(String[] args)
    {
        BinarySearchST<Integer, String> myBS = new BinarySearchST<Integer, String>(6);
        System.out.println("now size is:");
        System.out.println(myBS.size());

        myBS.put(1, "aaa");
        myBS.put(3, "ccc");
        myBS.put(2, "bbb");
        myBS.put(6, "aaa");
        myBS.put(4, "ccc");
        myBS.put(5, "bbb");

        String ret = myBS.get(2);
        System.out.println("second value is:");
        System.out.println(ret);

        Iterable<Integer> myIterable = myBS.keys(2,5);
        Iterator<Integer> myIt = myIterable.iterator();
        System.out.println("Iterable 2 to 5:");
        while(myIt.hasNext())
        {
            System.out.println(myIt.next());
        }
    }

}
