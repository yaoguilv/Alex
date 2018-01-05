#ifndef INSERTION_H
#define INSERTION_H
class Insertion {

};
#endif
public static <T extends Comparable<T>> void sort(T[] a)
{
    // Sort a[] into increasing order.
    int N = a.length;
    for(int i = 1; i < N; i++)
    {
        // Insert a[i] among a[i-1], a[i-2], a[i-3]
        for(int j = i; j > 0 && less(a[j], a[j - 1]); j--)
            exch(a, j, j - 1);
    }
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
