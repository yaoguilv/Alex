package C4.U1;

import C4.U1.Graph;
import C1.Unit3_Stacks.Stack;

public class DepthFirstPaths {
    // Has dfs() been called for this vertex?
    private boolean[] marked;
    // last vertex on known path to this vertex
    private int[] edgeTo;
    // source
    private final int s;

    public DepthFirstPaths(Graph G, int s)
    {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        dfs(G, s);
    }

    private void dfs(Graph G, int v)
    {
        marked[v] = true;
        for(int w : G.adj(v))
            if(!marked[w])
            {
                edgeTo[w] = v;
                dfs(G, w);
            }
    }

    public boolean hasPathTo(int v)
    {
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v)
    {
        if(!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<Integer>();
        for(int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return (Iterable<Integer>)path;
    }
}
