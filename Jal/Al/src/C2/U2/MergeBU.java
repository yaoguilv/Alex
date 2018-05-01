package C2.U2;

import C2.U1.Date;

public class MergeBU {
    // auxiliary array for merges
    private static Comparable<?>[] aux;

    public static <T extends Comparable<T>> void sort(T[] a)
    {
        // Do lg N passes of pairwise merges.
        int N = a.length;
        aux = new Comparable<?>[N];
        // sz: subaray size
        for(int sz = 1; sz < N; sz = sz + sz)
            // lo: subarray index
            for(int lo = 0; lo < N - sz; lo += sz + sz)
                merge(a, lo, lo + sz -1, Math.min(lo + sz + sz -1, N - 1));
    }

    @SuppressWarnings("unchecked")
    private static <T extends Comparable<T>> void merge(T[] a, int lo, int mid, int hi)
    {
        // Merge a[lo..mid] with a[mid+1..hi].
        int i = lo, j = mid + 1;

        for(int k = lo; k <= hi; k++)
            aux[k] = a[k];

        for(int k = lo; k <= hi; k++)
        {
            if (i > mid)
                a[k] = (T)aux[j++];
            else if(j > hi)
                a[k] = (T)aux[i++];
            else if(less((T)aux[j], (T)aux[i]))
                a[k] = (T)aux[j++];
            else
                a[k] = (T)aux[i++];
        }
    }

    @SuppressWarnings (value="unused")
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
        MergeBU.sort(dat);
        for(int i = 0; i < 3; i++)
        {
            System.out.println(dat[i]);
        }
    }

}
