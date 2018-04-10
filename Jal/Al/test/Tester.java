package test;

import java.util.*;
import C4.U1.Graph;
import C4.U1.SymbolGraph;
import C4.U1.DegreesOfSeparation;
import C4.U2.Digraph;
import C1.Unit3_Stacks.Bag;
import C4.U2.DirectedDFS;

public class Tester {
    public static void main(String[] args)
    {
        Digraph G = new Digraph(args[0]);
        Bag<Integer> sources = new Bag<Integer>();
        for(int i = 1; i < args.length; i++)
            sources.add(Integer.parseInt(args[i]));

        DirectedDFS reachable = new DirectedDFS(G, sources);

        for(int v = 0; v < G.V(); v++)
            if(reachable.marked(v))
                StdLib.StdOut.print(v + " ");
        StdLib.StdOut.println();
    }
}
