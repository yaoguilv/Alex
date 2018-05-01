package C4.U3;

public class PrimMST {
    // // shortest edge from tree vertex
    // private Edge[] edgeTo;
    // // distTo[w] = edgeTo[w].weight()
    // private double[] distTo;
    // // true if v on tree
    // private boolean[] marked;
    // // eligible crossing edges
    // private IndexMinPQ<Double> pq;

    // public PrimMST(EdgeWeightedGraph G)
    // {
    //     edgeTo = new Edge[G.V()];
    //     distTo = new double[G.V()];
    //     marked = new boolean[G.V()];
    //     for(int v = 0; v < G.V(); v++)
    //         distTo[v] = Double.POSITIVE_INFINITY;
    //     pq = new IndexMinPQ<Double>(G.V());

    //     distTo[0] = 0.0;
    //     // Initialize pq with 0, weight 0.
    //     pq.insert(0, 0.0);
    //     while(!pq.isEmpty())
    //         // Add closed vertex to tree.
    //         visit(G, pq.delMin());
    // }

    // private void visit(EdgeWeightedGraph G, int v)
    // {
    //     // Add v to tree; update data structures.
    //     marked[v] = true;
    //     for(Edge e : G.adj(v))
    //     {
    //         int w = e.other(v);
    //         // v-w is ineligible.
    //         if(marked[w])
    //             continue;
    //         if(e.weight() < distTo[w])
    //         {
    //             // Edge e is new best connection from tree to w.
    //             edgeTo[w] = e;
    //             distTo[w] = e.weight();
    //             if(pq.contains(w))
    //                 pq.change(w, distTo[w]);
    //             else
    //                 pq.insert(w, distTo[w]);
    //         }
    //     }
    // }

    // public Iterable<Edge> edges()
    // {

    // }

    // public double weight()
    // {

    // }
}
