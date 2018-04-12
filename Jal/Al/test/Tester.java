package test;

import C4.U2.Digraph;
import C1.Unit3_Stacks.Stack;
import C4.U2.DirectedCycle;
import C4.U2.DepthFirstOrder;
import C4.U2.Topological;
import C4.U2.SymbolDigraph;

public class Tester {
    public static void main(String[] args)
    {
        String filename = args[0];
        String separator = args[1];
        SymbolDigraph sg = new SymbolDigraph(filename, separator);

        Topological top = new Topological(sg.G());

        for(int v : top.order())
            StdLib.StdOut.println(sg.name(v));
    }
}
