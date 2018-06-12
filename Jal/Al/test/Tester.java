package test;

import StdLib.*;
import C5.U1.MSD;

public class Tester {
    public static void main(String[] args)
    {
        String[] a = In.readStrings(args[0]);

        int N = a.length;
        MSD.sort(a);
        for (int i = 0; i < N; i++)
            StdOut.println(a[i]);
    }
}
