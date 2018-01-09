package C2.U2;
public class Merge<T extends Comparable<T>> {
    // auxiliary array for merges
    private T[] aux;

    private void sort(T[] a)
    {
        T[] aux1 = new T[a.length];
        sort(a, 0, a.length - 1);
    }

    private void sort(T[] a, int lo, int hi)
    {
        // Sort a[lo..hi].
        if(hi <= lo) return;
        int mid = lo + (hi - lo)/2;
        // Sort left half.
        sort(a, lo, mid);
        // Sort right half.
        sort(a, mid + 1, hi);
        // Merge results
        merge(a, lo, mid, hi);
    }

    private void merge(T[] a, int lo, int mid, int hi)
    {
        // Merge a[lo..mid] with a[mid+1..hi].
        int i = lo, j = mid + 1;

        for(int k = lo; k <= hi; k++)
            aux[k] = a[k];

        for(int k = lo; k <= hi; k++)
        {
            if (i > mid)
                a[k] = aux[j++];
            else if(j > hi)
                a[k] = aux[i++];
            else if(less(aux[j], aux[i]))
                a[k] = aux[j++];
            else
                a[k] = aux[i++];
        }
    }

    private void exch(T[] a, int i, int j)
    {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private boolean less(T v, T w)
    {
        return v.compareTo(w) < 0;
    }

    public boolean isSorteed(T[] a)
    {
        for(int i = 1; i < a.length; i++)
            if(less(a[i], a[i - 1])) return false;
        return true;
    }
}
