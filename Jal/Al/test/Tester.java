package test;

import C4.U3.Edge;
import C4.U3.EdgeWeightedGraph;
import C4.U3.PrimMST;

public class Tester {
    public static void main(String[] args)
    {
        StdLib.In in = new StdLib.In(args[0]);
        EdgeWeightedGraph G;
        G = new EdgeWeightedGraph(in);

        PrimMST mst = new PrimMST(G);
        for(Edge e : mst.edges())
            StdLib.StdOut.println(e);
        StdLib.StdOut.println(mst.weight());
    }
}
