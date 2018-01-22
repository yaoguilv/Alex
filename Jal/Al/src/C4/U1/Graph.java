package C4.U1;

import C1.Unit3_Stacks.Bag;

public class Graph {
    // number of vertices
    private final int V;
    // number of edges
    private int E;
    // adjacency lists
    private Bag<Integer>[] adj;

    @SuppressWarnings("unchecked")
    public Graph(int V)
    {
        this.V = V;
        this.E = 0;
        // Create array of lists.
        adj = (Bag<Integer>[]) new Bag<?>[V];
        // Initialize all lists
        for(int v = 0; v < V; v++)
            // to empty
            adj[v] = new Bag<Integer>();
    }

    public Graph(StdLib.In in)
    {
        // Read V adn construct this graph.
        this(in.readInt());
        // Read E.
        int E = in.readInt();
        for(int i = 0; i < E; i++)
        {
            // Add an edge
            // Read a vertex,
            int v = in.readInt();
            // read another vertex,
            int w = in.readInt();
            // and add edge connecting them.
            addEdge(v, w);
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

    public void addEdge(int v, int w)
    {
        // Add w to v's list.
        adj[v].add(w);
        // Add v to w's list.
        adj[w].add(v);
        E++;
    }

    public Iterable<Integer> adj(int v)
    {
        return adj[v];
    }

    public static int degree(Graph G, int v)
    {
        int degree = 0;
        for(int w : G.adj(v))
            degree++;
        return degree;
    }

    public static int maxDegere(Graph G)
    {
        int max = 0;
        for(int v = 0; v < G.V(); v++)
        {
            if(degree(G, v) > max)
                max = degree(G, v);
        }
        return max;
    }

    public static int avgDegree(Graph G)
    {
        return 2 * G.E() / G.V();
    }

    public static int numberOfSelfLoops(Graph G)
    {
        int count = 0;
        for(int v = 0; v < G.V(); v++)
            for(int w : G.adj(v))
                if(v == w) count++;
        // each edge counted twice
        return count/2;
    }

    public String toString()
    {
        String s = V + " vertices, " + E + " edges\n";
        for(int v = 0; v < V; v++)
        {
            s += v + ": ";
            for(int w : this.adj(v))
                s += w + " ";
            s += "\n";
        }
        return s;
    }
}
