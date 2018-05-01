package C4.U3;

import C2.U4.MinPQ;
import C1.Unit3_Stacks.Queue;
import C4.U3.EdgeWeightedGraph;

public class LazyPrimMST {
    private double weight;
    // MST vertices
    private boolean[] marked;
    // MST edges
    private Queue<Edge> mst;
    // crossing (and ineligible) edges
    private MinPQ<Edge> pq;

    public LazyPrimMST(EdgeWeightedGraph G)
    {
        pq = new MinPQ<Edge>();
        marked = new boolean[G.V()];
        mst = new Queue<Edge>();

        // assumes G is connected
        visit(G, 0);
        while(!pq.isEmpty())
        {
            // Get lowest-weight edge from pq.
            Edge e = pq.delMin();
            int v = e.either(), w = e.other(v);
            // Skip if ineligible.
            if(marked[v] && marked[w]) continue;
            // Add edge to tree.
            mst.enqueue(e);
            weight += e.weight();
            // Add vertex to tree(either v or w).
            if(!marked[v])
                visit(G, v);
            if(!marked[w])
                visit(G, w);
        }
    }

    private void visit(EdgeWeightedGraph G, int v)
    {
        // Mark v and add to pq all edges from v to unmarked vertices.
        marked[v] = true;
        for(Edge e : G.adj(v))
            if(!marked[e.other(v)])
                pq.insert(e);
    }

    public Iterable<Edge> edges()
    {
        return mst;
    }

    public double weight()
    {
        return weight;
    }
}
