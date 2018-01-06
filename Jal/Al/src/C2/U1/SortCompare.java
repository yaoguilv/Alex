package C2.U1;

public class SortCompare {
    public static double time(String alg, Double[] a)
    {
        Stopwatch timer = new Stopwatch();
        if(alg.equals("Insertion")) Insertion.sort(a);
        if(alg.equals("Selection")) Selection.sort(a);
        return timer.elapsedTime();
    }

    public static double timeRandomInput(String alg, int N, int T)
    {
        // Use alg to sort T random arrays of length N.
        double total = 0.0;
        Double[] a = new Double[N];
        for(int t = 0; t < T; t++)
        {
            // Perform one experiment(generate and sort an array)
            for(int i = 0; i < N; i++)
                a[i] = StdLib.StdRandom.uniform();
            total += time(alg, a);
        }
        return total;
    }
}
