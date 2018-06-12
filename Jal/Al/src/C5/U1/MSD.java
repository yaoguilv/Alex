package C5.U1;

import C2.U1.Insertion;

public class MSD {
    // radix
    private static int R = 256;
    // cutoff for small subarrays
    private static final int M = 125;
    // auxiliary array for distribution
    private static String[] aux;

    private static int charAt(String s, int d)
    {
        if(d < s.length())
            return s.charAt(d);
        else
            return -1;
    }

    public static void sort(String[] a)
    {
        int N = a.length;
        aux = new String[N];
        sort(a, 0, N - 1, 0);
    }

    private static void sort(String[] a, int lo, int hi, int d)
    {
        // Sort form a[lo] to a[hi], starting at the dth character.
        if(hi <= lo + M)
        {
            insertion(a, lo, hi, d);
            return;
        }

        // Compute frequency counts.
        int[] count = new int[R + 2];
        for(int i = lo; i <= hi; i++)
            count[charAt(a[i], d) + 2]++;

        // Transform counts to indices.
        for(int r = 0; r < R + 1; r++)
            count[r + 1] += count[r];

        // Distribute.
        for(int i = lo; i <= hi; i++)
            aux[count[charAt(a[i], d) + 1]++] = a[i];
        // Copy back
        for(int i = lo; i <= hi; i++)
            a[i] = aux[i - lo];

        // Recursively sort for each character value.
        for(int r = 0; r < R; r++)
            sort(a, lo + count[r], lo + count[r + 1] - 1, d + 1);
    }

    // return dth character of s, -1 if d = length of string
    private static void insertion(String[] a, int lo, int hi, int d) {
        for (int i = lo; i <= hi; i++)
            for (int j = i; j > lo && less(a[j], a[j-1], d); j--)
                exch(a, j, j-1);
    }

    // exchange a[i] and a[j]
    private static void exch(String[] a, int i, int j) {
        String temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // is v less than w, starting at character d
    private static boolean less(String v, String w, int d) {
        assert v.substring(0, d).equals(w.substring(0, d));
        return v.substring(d).compareTo(w.substring(d)) < 0;
    }

}
