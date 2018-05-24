package C4.U4;

import C1.Unit3_Stacks.*;
import StdLib.*;

public class BellmanFordSP {
    // length of path to v
    private double[] distTo;
    // last edge on path to v
    private DirectedEdge[] edgeTo;
    // Is this vertex on the queue?
    private boolean[] onQ;
    // vertices being relaxed
    private Queue<Integer> queue;
    // number of calls to relax()
    private int cost;
    // negative cycle in edgeTo[]?
    private Iterable<DirectedEdge> cycle;

    public BellmanFordSP(EdgeWeightedDigraph G, int s)
    {
        distTo = new double[G.V()];
        edgeTo = new DirectedEdge[G.V()];
        onQ = new boolean[G.V()];
        queue = new Queue<Integer>();
        for(int v = 0; v < G.V(); v++)
            distTo[v] = Double.POSITIVE_INFINITY;
        distTo[s] = 0.0;
        queue.enqueue(s);
        onQ[s] = true;
        while(!queue.isEmpty() && !this.hasNegativeCycle())
        {
            int v = queue.dequeue();
            onQ[v] = false;
            relax(G, v);
        }
    }

    private void relax(EdgeWeightedDigraph G, int v)
    {
        for(DirectedEdge e : G.adj(v))
        {
            int w = e.to();
            if(distTo[w] > distTo[v] + e.weight())
            {
                distTo[w] = distTo[v] + e.weight();
                edgeTo[w] = e;
                if(!onQ[w])
                {
                    queue.enqueue(w);
                    onQ[w] = true;
                }
            }
            if(cost++ % G.V() == 0)
                findNegativeCycle();
        }
    }

    public double distTo(int v)
    {
        return distTo[v];
    }

    public boolean hasPathTo(int v)
    {
        return distTo[v] < Double.POSITIVE_INFINITY;
    }

    public Iterable<DirectedEdge> pathTo(int v)
    {
        if(!hasPathTo(v))
            return null;
        Stack<DirectedEdge> path = new Stack<DirectedEdge>();
        for(DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.from()])
            path.push(e);
        return path;

    }

    private void findNegativeCycle()
    {
        int V = edgeTo.length;
        EdgeWeightedDigraph spt;
        spt = new EdgeWeightedDigraph(V);
        for(int v = 0; v < V; v++)
            if(edgeTo[v] != null)
                spt.addEdge(edgeTo[v]);

        EdgeWeightedDirectedCycle cf;
        cf = new EdgeWeightedDirectedCycle(spt);

        cycle = cf.cycle();
    }

    public boolean hasNegativeCycle()
    {
        return cycle != null;
    }

    public Iterable<DirectedEdge> negativeCycle()
    {
        return cycle;
    }

    public static void main(String[] args)
    {
        EdgeWeightedDigraph G;
        G = new EdgeWeightedDigraph(new In(args[0]));
        int s = Integer.parseInt(args[1]);
        BellmanFordSP sp = new BellmanFordSP(G, s);

        if(sp.hasNegativeCycle())
        {
            for(DirectedEdge e : sp.negativeCycle())
                StdOut.print(e + "    ");
            StdOut.println();
        }
        else
        {
            for(int t = 0; t < G.V(); t++)
            {
                StdOut.print(s + " to " + t);
                StdOut.printf(" (%4.2f): ", sp.distTo(t));
                if(sp.hasPathTo(t))
                    for(DirectedEdge e : sp.pathTo(t))
                        StdOut.print(e + "    ");
                StdOut.println();
            }
        }
    }
}
