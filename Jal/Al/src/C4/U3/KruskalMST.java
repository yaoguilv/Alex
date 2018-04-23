package C4.U3;

public class KruskalMST {
    // private Queue<Edge> mst;

    // public KruskalMST(EdgeWeightedGraph G)
    // {
    //     mst = new Queue<Edge>();
    //     MinPQ<Edge> pq = new MinPQ<Edge>(G.edges());
    //     UF uf = new UF(G.V());

    //     while(!pq.isEmpty() && mst.size() < G.V() - 1)
    //     {
    //         // Get min weight edge on pq and its vertices.
    //         Edge e = pq.delMin();
    //         int v = e.either(), w = e.other(v);
    //         // Ignore ineligible edges.
    //         if(uf.connected(v, w))
    //             continue;
    //         // Merge components.
    //         uf.union(v, w);
    //         // Add edge to mst.
    //         mst.enqueue(e);
    //     }
    // }

    // public Iterable<Edge> edges()
    // {
    //     return mst;
    // }

    // public double weight()
    // {

    // }
}
