package test;

import C2.U1.Insertion;
import C2.U1.Date;
import C2.U1.Selection;
import C2.U1.SortCompare;
import C2.U1.Shell;
import C2.U1.BubbleSort;
import java.util.*;

public class Tester {
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


