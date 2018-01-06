package test;

import C2.U1.Insertion;
import C2.U1.Date;
import C2.U1.Selection;
import C2.U1.SortCompare;
import java.util.*;

public class Tester {
    public static void main(String[] args)
    {
        String alg1 = args[0];
        String alg2 = args[1];
        int N = Integer.parseInt(args[2]);
        int T = Integer.parseInt(args[3]);
        double t1 = timeRandomInput(alg1, N, T); // total for alg1
        double t2 = timeRandomInput(alg2, N, T); // total for alg2
        StdLib.StdOut.printf("For %d random Doubles\n      %s is", N, alg1);
        StdLib.StdOut.printf(" %.1f times faster than %s\n", t2/t1, alg2);
    }
}
