package C4.U2;

import C4.U2.Digraph;

public class KosarajuSCC {
    // reached vertices
    private boolean[] marked;
    // component identifiers
    private int[] id;
    // number of strong components
    private int count;

    public KosarajuSCC(Digraph G)
    {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        DepthFirstOrder order = new DepthFirstOrder(G.reverse());
        for(int s : order.reversePost())
            if(!marked[s])
            {
                dfs(G, s);
                count++;
            }
    }

    private void dfs(Digraph G, int v)
    {
        marked[v] = true;
        id[v] = count;
        for(int w : G.adj(v))
            if(!marked[w])
                dfs(G, w);
    }

    public boolean stronglyConnected(int v, int w)
    {
        return id[v] == id[w];
    }

    public int id(int v)
    {
        return id[v];
    }

    public int count()
    {
        return count;
    }

    public static void main(String[] args)
    {
        String filename = args[0];
        Digraph dg = new Digraph(filename);

        KosarajuSCC ks = new KosarajuSCC(dg);

        StdLib.StdOut.println(ks.count());
        for(int i = 0; i < ks.count(); i++)
        {
            for(int j = 0; j < dg.V(); j++)
            {
                if(ks.id(j) == i)
                {
                    StdLib.StdOut.print(j);
                    StdLib.StdOut.print("  ");
                }
            }
            StdLib.StdOut.println();
        }
    }
}
