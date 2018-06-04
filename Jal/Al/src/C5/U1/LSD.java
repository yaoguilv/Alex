package C5.U1;

public class LSD {
    public static void sort(String[] a, int W)
    {
        // Sort a[] on leading W characters.
        int N = a.length;
        int R = 256;
        String[] aux = new String[N];

        for(int d = W - 1; d >= 0; d--)
        {
            // Sort by key-indexed counting on dth char.
            // Compute frequency counts.
            int[] count = new int[R + 1];
            for(int i = 0; i < N; i++)
                count[a[i].charAt(d) + 1]++;

            // Transform counts to indices.
            for(int r = 0; r < R; r++)
                count[r+1] += count[r];

            // Distribute.
            for(int i = 0; i < N; i++)
                aux[count[a[i].charAt(d)]++] = a[i];

            // Copy back.
            for(int i = 0; i < N; i++)
                a[i] = aux[i];
        }
    }
}
