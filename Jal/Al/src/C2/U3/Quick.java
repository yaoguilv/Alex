package C2.U3;
import C2.U1.Date;
import java.util.*;

public class Quick {
    public static <T extends Comparable<T>> void sort(T[] a)
    {
        // Eliminate dependence on input.
        StdLib.StdRandom.shuffle(a);
        sort(a, 0, a.length - 1);
    }

    private static <T extends Comparable<T>> void sort(T[] a, int lo, int hi)
    {
        if(hi <= lo) return;

        int j = partition(a, lo, hi);
        // Sort left parta[lo .. j-1].
        sort(a, lo, j - 1);
        // Sort right part a[j+1 .. hi].
        sort(a, j + 1, hi);
    }

    private static <T extends Comparable<T>> int partition(T[] a, int lo, int hi)
    {
        // Partition into a[lo..i-1], a[i],a[i+1..hi].
        // left and right scan indices
        int i = lo, j = hi + 1;
        // partitioning item
        T v = a[lo];
        while(true)
        {
            // Scan right, scan left, check for scan complete, and exchange.
            while(less(a[++i], v))
                if(i == hi) break;
            while(less(v, a[--j]))
                if(j == lo) break;
            if(i >= j) break;
            exch(a, i, j);
        }
        // Put v = a[j] into position
        exch(a, lo, j);
        // with a[lo..j-1] <= a[j] <= a[j+1..hi].
        return j;
    }

    private static <T extends Comparable<T>> void exch(T[] a, int i, int j)
    {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static <T extends Comparable<T>> boolean less(T v, T w)
    {
        return v.compareTo(w) < 0;
    }

    public static <T extends Comparable<T>> boolean isSorteed(T[] a)
    {
        for(int i = 1; i < a.length; i++)
            if(less(a[i], a[i - 1])) return false;
        return true;
    }

    public static void main(String[] args)
    {
        Date[] dat = new Date[]{new Date(1, 1, 2010),
        new Date(1, 1, 2017), new Date(1, 1, 2015)};
        Quick.sort(dat);
        for(int i = 0; i < 3; i++)
        {
            System.out.println(dat[i]);
        }
    }

}

