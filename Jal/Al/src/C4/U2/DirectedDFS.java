package C4.U2;

import java.util.*;
import C4.U1.Graph;
import C4.U1.SymbolGraph;
import C4.U1.DegreesOfSeparation;
import C4.U2.Digraph;
import C1.Unit3_Stacks.Bag;
import C4.U2.DirectedDFS;


public class DirectedDFS {
    private boolean[] marked;

    public DirectedDFS(Digraph G, int s)
    {
        marked = new boolean[G.V()];
        dfs(G, s);
    }

    public DirectedDFS(Digraph G, Iterable<Integer> sources)
    {
        marked = new boolean[G.V()];
        for(int s : sources)
            if(!marked[s])
                dfs(G, s);
    }

    private void dfs(Digraph G, int v)
    {
        marked[v] = true;
        for(int w : G.adj(v))
            if(!marked[w])
                dfs(G, w);
    }

    public boolean marked(int v)
    {
        return marked[v];
    }

    public static void main(String[] args)
    {
        Digraph G = new Digraph(args[0]);
        Bag<Integer> sources = new Bag<Integer>();
        for(int i = 1; i < args.length; i++)
            sources.add(Integer.parseInt(args[i]));

        DirectedDFS reachable = new DirectedDFS(G, sources);

        for(int v = 0; v < G.V(); v++)
            if(reachable.marked(v))
                StdLib.StdOut.print(v + " ");
        StdLib.StdOut.println();
    }

}
