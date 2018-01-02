package C2.U1;

import C2.U1.Date;

public class Selection {
    public static <T extends Comparable<T>> void sort(T[] a)
    {
        int N = a.length;
        for(int i = 0; i < N; i++)
        {
            // Exchange a[i] with smallest entry in a[i+1...N).
            int min = i;
            for(int j = i + 1; j < N; j++)
                if(less(a[j], a[min])) min = j;
            exch(a, i, min);
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

    public static void main(String[] args)
    {
        Date[] dat = new Date[]{new Date(1, 1, 2010),
        new Date(1, 1, 2017), new Date(1, 1, 2015)};
        Selection.sort(dat);
        for(int i = 0; i < 3; i++)
        {
            System.out.println(dat[i]);
        }
    }
}
