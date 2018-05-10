package test;

import C4.U4.DirectedEdge;
import C4.U4.EdgeWeightedDigraph;

public class Tester {
    public static void main(String[] args)
    {
        StdLib.In in = new StdLib.In(args[0]);
        EdgeWeightedDigraph myEWD = new EdgeWeightedDigraph(in);

        System.out.println(myEWD.V());
        System.out.println(myEWD.E());

        System.out.println("now vertex 5's following edges:");
        Iterable<DirectedEdge> myAdj = myEWD.adj(5);
        for(DirectedEdge myEdge : myAdj)
        {
            System.out.println(myEdge.toString());
        }

        System.out.println("now all Edges:");
        Iterable<DirectedEdge> myAll = myEWD.edges();
        for(DirectedEdge myEdge : myAll)
        {
            System.out.println(myEdge.toString());
        }
    }
}
