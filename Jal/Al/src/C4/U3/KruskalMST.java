package C4.U3;

import C1.Unit5_UnionFind.UF;
import C2.U4.MinPQ;
import C1.Unit3_Stacks.Queue;
import C4.U3.Edge;
import C4.U3.EdgeWeightedGraph;


public class KruskalMST {
    private Queue<Edge> mst;
    private double weight;

    public KruskalMST(EdgeWeightedGraph G)
    {
        mst = new Queue<Edge>();
        MinPQ<Edge> pq = new MinPQ<Edge>(G.edges());
        UF uf = new UF(G.V());

        while(!pq.isEmpty() && mst.size() < G.V() - 1)
        {
            // Get min weight edge on pq and its vertices.
            Edge e = pq.delMin();
            int v = e.either(), w = e.other(v);
            // Ignore ineligible edges.
            if(uf.connected(v, w))
                continue;
            // Merge components.
            uf.union(v, w);
            // Add edge to mst.
            mst.enqueue(e);
            weight += e.weight();
        }
    }

    public Iterable<Edge> edges()
    {
        return mst;
    }

    public double weight()
    {
        return weight;
    }

    public static void main(String[] args)
    {
        StdLib.In in = new StdLib.In(args[0]);
        EdgeWeightedGraph G;
        G = new EdgeWeightedGraph(in);

        KruskalMST mst = new KruskalMST(G);
        for(Edge e : mst.edges())
            StdLib.StdOut.println(e);
        StdLib.StdOut.println(mst.weight());
    }

}
