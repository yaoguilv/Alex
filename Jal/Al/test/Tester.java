package test;

import C4.U2.Digraph;
import C4.U2.KosarajuSCC;

public class Tester {
    public static void main(String[] args)
    {
        String filename = args[0];
        Digraph dg = new Digraph(filename);

        KosarajuSCC ks = new KosarajuSCC(dg);

        StdLib.StdOut.println(ks.count());
        for(int i = 0; i < ks.count(); i++)
        {
            for(int j = 0; j < dg.V(); j++)
            {
                if(ks.id(j) == i)
                {
                    StdLib.StdOut.print(j);
                    StdLib.StdOut.print("  ");
                }
            }
            StdLib.StdOut.println();
        }
    }
}
