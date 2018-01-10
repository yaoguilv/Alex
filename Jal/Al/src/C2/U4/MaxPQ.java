package C2.U4;

import C2.U1.Date;
import java.util.*;


public class MaxPQ<Key extends Comparable<Key>> {
    // heap-ordered complete binary tree.
    private Key[] pq;
    // in pq[1..N] with pq[0] unused
    private int N = 0;

    @SuppressWarnings("unchecked")
    public MaxPQ(int maxN)
    {
        pq = (Key[]) new Comparable<?>[maxN + 1];
    }

    public boolean isEmpty()
    {
        return N == 0;
    }

    public int size()
    {
        return N;
    }

    public void insert(Key v)
    {
        pq[++N] = v;
        swim(N);
    }

    public Key delMax()
    {
        // Retrieve max key from top.
        Key max = pq[1];
        // Exchange with last item.
        exch(1, N--);
        // Avoid loitering.
        pq[N + 1] = null;
        // Restore heap property.
        sink(1);
        return max;
    }

    private boolean less(int i, int j)
    {
        return pq[i].compareTo(pq[j]) < 0;
    }

    private void exch(int i, int j)
    {
        Key t = pq[i];
        pq[i]= pq[j];
        pq[j] = t;
    }

    private void swim(int k)
    {
        while(k > 1 && less(k/2, k))
        {
            exch(k/2, k);
            k = k/2;
        }
    }

    private void sink(int k)
    {
        while(2 * k <= N)
        {
            int j = 2 * k;
            if(j < N && less(j, j + 1)) j++;
            if(!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    public static void main(String[] args)
    {
        Date[] dat = new Date[]{new Date(1, 1, 2010),
        new Date(1, 1, 2017), new Date(1, 1, 2015)};
        MaxPQ<Date> myMaxPQ = new MaxPQ<Date>(3);
        System.out.println("isEmpty: ");
        System.out.println(myMaxPQ.isEmpty());

        myMaxPQ.insert(new Date(1, 1, 2010));
        System.out.println("now size:");
        System.out.println(myMaxPQ.size());

        myMaxPQ.insert(new Date(1, 1, 2017));
        myMaxPQ.insert(new Date(1, 1, 2015));
        System.out.println("now size:");
        System.out.println(myMaxPQ.size());

        Date myDat = myMaxPQ.delMax();
        System.out.println("delete Max:");
        System.out.println(myDat);
        System.out.println("now size:");
        System.out.println(myMaxPQ.size());
    }

}
