package C2.U3;

import C2.U1.Date;

public class Quick3way {
    public static <T extends Comparable<T>> void sort(T[] a)
    {
        // Eliminate dependence on input.
        StdLib.StdRandom.shuffle(a);
        sort(a, 0, a.length - 1);
    }

    private static <T extends Comparable<T>> void sort(T[] a, int lo, int hi)
    {
        if(hi <= lo) return;
        int lt = lo, i = lo + 1, gt = hi;
        T v = a[lo];
        while(i <= gt)
        {
            int cmp = a[i].compareTo(v);
            if(cmp < 0) exch(a, lt++, i++);
            else if(cmp > 0) exch(a, i, gt--);
            else i++;
        }
        // Now a[lo .. lt-1] < v = a[lt .. gt] < a[gt+1 .. hi].
        sort(a, lo, lt - 1);
        sort(a, gt + 1, hi);
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
        Quick3way.sort(dat);
        for(int i = 0; i < 3; i++)
        {
            System.out.println(dat[i]);
        }
    }

}
