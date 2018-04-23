package test;

import C4.U2.Digraph;
import C4.U2.KosarajuSCC;
import C4.U3.Edge;
import C4.U3.EdgeWeightedGraph;
import C4.U3.LazyPrimMST;

public class Tester {
    public static void main(String[] args)
    {
        StdLib.In in = new StdLib.In(args[0]);
        EdgeWeightedGraph G;
        G = new EdgeWeightedGraph(in);

        LazyPrimMST mst = new LazyPrimMST(G);
        for(Edge e : mst.edges())
            StdLib.StdOut.println(e);
        StdLib.StdOut.println(mst.weight());
    }
}
