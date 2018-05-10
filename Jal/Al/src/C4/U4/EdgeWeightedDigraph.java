package C4.U4;

import StdLib.*;
import C1.Unit3_Stacks.Bag;
import java.util.*;

public class EdgeWeightedDigraph {
    // number of vertices
    private final int V;
    // number of edges
    private int E;
    // adjacency lists
    private Bag<DirectedEdge>[] adj;

    @SuppressWarnings("unchecked")
    public EdgeWeightedDigraph(int V)
    {
        this.V = V;
        this.E = 0;
        adj = (Bag<DirectedEdge>[]) new Bag[V];
        for(int v = 0; v < V; v++)
            adj[v] = new Bag<DirectedEdge>();
    }

    public EdgeWeightedDigraph(In in)
    {
        this(in.readInt());
        int E = in.readInt();
        for(int i = 0; i < E; i++)
        {
            int v = in.readInt();
            int w = in.readInt();
            double weight = in.readDouble();
            DirectedEdge e = new DirectedEdge(v, w, weight);
            addEdge(e);
        }
    }

    public int V()
    {
        return V;
    }

    public int E()
    {
        return E;
    }

    public void addEdge(DirectedEdge e)
    {
        adj[e.from()].add(e);
        E++;
    }

    public Iterable<DirectedEdge> adj(int v)
    {
        return adj[v];
    }

    public Iterable<DirectedEdge> edges()
    {
        Bag<DirectedEdge> bag = new Bag<DirectedEdge>();
        for(int v = 0; v < V; v++)
            for(DirectedEdge e : adj[v])
                bag.add(e);
        return bag;
    }
}
