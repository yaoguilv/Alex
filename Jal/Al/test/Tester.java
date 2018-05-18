package test;

import C4.U4.DirectedEdge;
import C4.U4.EdgeWeightedDigraph;
import StdLib.*;
import C4.U4.AcyclicLP;

public class Tester {
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        int N = in.readInt();
        in.readLine();
        EdgeWeightedDigraph G;
        G = new EdgeWeightedDigraph(2 * N + 2);

        int s = 2 * N, t = 2 * N + 1;
        for(int i = 0; i < N;  i++)
        {
            String[] a = in.readLine().split("\\s+");
            double duration = Double.parseDouble(a[0]);
            G.addEdge(new DirectedEdge(i, i + N, duration));
            G.addEdge(new DirectedEdge(s, i, 0.0));
            G.addEdge(new DirectedEdge(i + N, t, 0.0));
            for(int j = 1; j < a.length; j++)
            {
                int successor = Integer.parseInt(a[j]);
                G.addEdge(new DirectedEdge(i + N, successor, 0.0));
            }
        }
        System.out.println("now all Edges:");
        Iterable<DirectedEdge> myAll = G.edges();
        for(DirectedEdge myEdge : myAll)
        {
            System.out.println(myEdge.toString());
        }


        AcyclicLP lp = new AcyclicLP(G, s);

        StdOut.println("Start times:");
        for(int i = 0; i < N; i++)
            StdOut.printf("%4d: %5.1f\n", i, lp.distTo(i));
        StdOut.printf("Finish time: %5.1f\n", lp.distTo(t));
    }
}
