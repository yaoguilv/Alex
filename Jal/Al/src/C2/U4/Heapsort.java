package C2.U4;

import C2.U1.Date;

public class Heapsort {
    // just can sort the [1..N] numbers, no 0 number
    public static <T extends Comparable<T>> void sort(T[] a)
    {
        // sink method only operate the [1..N] elements
        // because 1*2 = 2,2*2=4... (it is binary tree) ,while 0*2 = 0
        int N = a.length - 1;
        for(int k = N/2; k >= 1; k--)
            sink(a, k, N);
        while(N > 1)
        {
            exch(a, 1, N--);
            sink(a, 1, N);
        }
    }

    private static <T extends Comparable<T>> void sink(T[] a, int k, int N)
    {
        while(2 * k <= N)
        {
            int j = 2 * k;
            if(j < N && less(a, j, j + 1)) j++;
            if(!less(a, k, j)) break;
            exch(a, k, j);
            k = j;
        }
    }

    private static <T extends Comparable<T>> boolean less(T[] a, int i, int j)
    {
        return a[i].compareTo(a[j]) < 0;
    }

    private static <T extends Comparable<T>> void exch(T[] a, int i, int j)
    {
        T t = a[i];
        a[i]= a[j];
        a[j] = t;
    }

    public static void main(String[] args)
    {
        Date[] dat = new Date[]{null, new Date(1, 1, 2010),
        new Date(1, 1, 2017), new Date(1, 1, 2015)};
        Heapsort.sort(dat);
        for(int i = 1; i < 4; i++)
        {
            System.out.println(dat[i]);
        }
    }

}
