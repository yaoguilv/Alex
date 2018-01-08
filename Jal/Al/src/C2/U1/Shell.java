package C2.U1;
public class Shell {
    public static <T extends Comparable<T>> void sort(T[] a)
    {
        // Sort a[] into increasing order.
        int N = a.length;
        int h = 1;
        while(h < N/3)
            h = 3 * h + 1;
        while(h >= 1)
        {
            // h-sort the array.
            for(int i = h; i < N; i++)
            {
                // Insert a[i] among a[i-h], a[i-2*h],a[i-3*h]... .
                for(int j = i; j >= h && less(a[j], a[j - h]); j-= h)
                    exch(a, j, j - h);
            }
            h = h/3;
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
        Double[] a = new Double[10];
        for(int i = 0; i < 10; i++)
            a[i] = StdLib.StdRandom.uniform();
        for(int i = 0; i < 10; i++)
            System.out.println(a[i]);
        System.out.println("------");
        Shell.sort(a);
        for(int i = 0; i < 10; i++)
            System.out.println(a[i]);
    }
}
