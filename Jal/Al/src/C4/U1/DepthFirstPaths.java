package C4.U1;

import java.util.*;
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

    public static void main(String[] args)
    {
        Graph myG = new Graph(7);
        myG.addEdge(0, 1);
        myG.addEdge(0, 2);
        myG.addEdge(0, 5);
        myG.addEdge(0, 6);
        myG.addEdge(5, 3);
        myG.addEdge(5, 4);
        myG.addEdge(3, 4);
        myG.addEdge(4, 6);
        String outContext = myG.toString();
        System.out.print(outContext);

        int s = 0;
        DepthFirstPaths search = new DepthFirstPaths(myG, s);
        for(int v = 0; v < myG.V(); v++)
        {
            StdLib.StdOut.print(s + " to " + v + ": ");
            if(search.hasPathTo(v))
                for(int x : search.pathTo(v))
                    if(x == s) StdLib.StdOut.print(x);
                    else StdLib.StdOut.print("-" + x);
            StdLib.StdOut.println();
        }
    }

}
