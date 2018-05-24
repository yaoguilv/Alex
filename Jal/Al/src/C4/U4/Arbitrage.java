package C4.U4;

import C4.U4.DirectedEdge;
import C4.U4.EdgeWeightedDigraph;
import StdLib.*;
import C4.U4.BellmanFordSP;

public class Arbitrage {
    public static void main(String[] args)
    {
        StdLib.In in = new In(args[0]);
        int V = in.readInt();
        System.out.println(V);
        String[] name = new String[V];
        EdgeWeightedDigraph G = new EdgeWeightedDigraph(V);
        for(int v = 0; v < V; v++)
        {
            name[v] = in.readString();
            for(int w = 0; w < V; w++)
            {
                double rate = in.readDouble();
                DirectedEdge e = new DirectedEdge(v, w, -Math.log(rate));
                G.addEdge(e);
            }
        }

        BellmanFordSP spt = new BellmanFordSP(G, 0);
        if(spt.hasNegativeCycle())
        {
            double stake = 1000.0;
            for(DirectedEdge e : spt.negativeCycle())
            {
                StdOut.printf("%10.5f %s ", stake, name[e.from()]);
                stake *= Math.exp(-e.weight());
                StdOut.printf("= %10.5f %s\n", stake, name[e.to()]);
            }
        }
        else
            StdOut.println("No arbitrage opportunity");
    }

}
