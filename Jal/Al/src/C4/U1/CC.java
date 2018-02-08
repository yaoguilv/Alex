package C4.U1;

import C4.U1.Graph;
import C1.Unit3_Stacks.Bag;

public class CC {
    private boolean[] marked;
    private int[] id;
    private int count;

    public CC(Graph G)
    {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        for(int s = 0; s < G.V(); s++)
            if(!marked[s])
            {
                dfs(G, s);
                count++;
            }
    }

    private void dfs(Graph G, int v)
    {
        marked[v] = true;
        id[v] = count;
        for(int w : G.adj(v))
            if(!marked[w])
                dfs(G, w);
    }

    public boolean connected(int v, int w)
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

    @SuppressWarnings("unchecked")
    public static void main(String[] args)
    {
        Graph myG = new Graph(13);
        myG.addEdge(0, 1);
        myG.addEdge(0, 2);
        myG.addEdge(0, 5);
        myG.addEdge(0, 6);
        myG.addEdge(5, 3);
        myG.addEdge(5, 4);
        myG.addEdge(3, 4);
        myG.addEdge(4, 6);
        myG.addEdge(7, 8);
        myG.addEdge(9, 10);
        myG.addEdge(9, 11);
        myG.addEdge(9, 12);
        myG.addEdge(11, 12);
        String outContext = myG.toString();
        System.out.print(outContext);

        CC cc = new CC(myG);
        int M = cc.count();
        StdLib.StdOut.println(M + " components");

        Bag<Integer>[] components;
        components = (Bag<Integer>[]) new Bag<?>[M];
        for(int i = 0; i < M; i++)
            components[i] = new Bag<Integer>();
        for(int v = 0; v < myG.V(); v++)
            components[cc.id(v)].add(v);
        for(int i = 0; i < M; i++)
        {
            for(int v : components[i])
                StdLib.StdOut.print(v + " ");
            StdLib.StdOut.println();
        }
    }

}
