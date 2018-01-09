package C2.U1;

public class BubbleSort {
    public static <T extends Comparable<T>> void sort(T[] a)
    {
        int N = a.length;
        for(int i = 0; i < N - 1; i++)
        {
            for(int j = 0; j < N - 1 - i; j++)
            {
                if(less(a[j + 1], a[j]))
                {
                    exch(a, j, j + 1);
                }
            }
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
        BubbleSort.sort(a);
        for(int i = 0; i < 10; i++)
            System.out.println(a[i]);
    }
}
