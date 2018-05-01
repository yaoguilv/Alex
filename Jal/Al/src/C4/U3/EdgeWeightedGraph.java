package C4.U3;

import C4.U3.Edge;
import C1.Unit3_Stacks.Bag;

public class EdgeWeightedGraph {
    // number of vertices
    private final int V;
    // number of edges
    private int E;
    // adjacency lists
    private Bag<Edge>[] adj;

    @SuppressWarnings (value="unchecked")
    public EdgeWeightedGraph(int V)
    {
        this.V = V;
        this.E = 0;
        adj = (Bag<Edge>[]) new Bag[V];
        for(int v = 0; v < V; v++)
            adj[v] = new Bag<Edge>();
    }

    public EdgeWeightedGraph(StdLib.In in)
    {
        this(in.readInt());
        int E = in.readInt();
        for(int i = 0; i < E; i++)
        {
            int v = in.readInt();
            int w = in.readInt();
            double weight = in.readDouble();
            Edge e = new Edge(v, w, weight);
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

    public void addEdge(Edge e)
    {
        int v = e.either(), w = e.other(v);
        adj[v].add(e);
        adj[w].add(e);
        E++;
    }

    public Iterable<Edge> adj(int v)
    {
        return adj[v];
    }

    public Iterable<Edge> edges()
    {
        Bag<Edge> list = new Bag<Edge>();
        for(int v = 0; v < V; v++)
        {
            int selfLoops = 0;
            for(Edge e : adj(v))
            {
                if(e.other(v) > v)
                    list.add(e);
            }
        }
        return list;
    }
}
