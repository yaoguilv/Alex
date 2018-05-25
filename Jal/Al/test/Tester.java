package test;

import StdLib.*;
import C5.U1.Alphabet;

public class Tester {
    public static void main(String[] args)
    {
        Alphabet alpha = new Alphabet(args[0]);
        int R = alpha.R();
        int[] count = new int[R];

        In in = new In(args[1]);
        String s = in.readAll();
        int N = s.length();
        for(int i = 0; i < N; i++)
            if(alpha.contains(s.charAt(i)))
                count[alpha.toIndex(s.charAt(i))]++;

        for(int c = 0; c < R; c++)
            StdOut.println(alpha.toChar(c) + " " + count[c]);
    }
}
