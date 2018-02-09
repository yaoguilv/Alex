package C4.U1;

public class TwoColor {
    private boolean[] marked;
    private boolean[] color;
    private boolean isTwoColorable = true;

    public TwoColor(Graph G)
    {
        marked = new boolean[G.V()];
        color = new boolean[G.V()];
        for(int s = 0; s < G.V(); s++)
            if(!marked[s])
                dfs(G, s);
    }

    private void dfs(Graph G, int v)
    {
        marked[v] = true;
        for(int w : G.adj(v))
            if(!marked[w])
            {
                color[w] = !color[v];
                dfs(G, w);
            }
            else if(color[w] == color[v]) isTwoColorable = false;
    }

    public boolean isBipartite()
    {
        return isTwoColorable;
    }

    public static void main(String[] args)
    {
        Graph myG = new Graph(4);
        myG.addEdge(0, 1);
        myG.addEdge(1, 2);
        myG.addEdge(2, 3);
        myG.addEdge(3, 0);

        String outContext = myG.toString();
        System.out.println("myG:");
        System.out.print(outContext);

        System.out.println("myG is Bipartite:");
        TwoColor myTwoColor = new TwoColor(myG);
        System.out.println(myTwoColor.isBipartite());

        Graph myG2= new Graph(4);
        myG2.addEdge(0, 1);
        myG2.addEdge(1, 2);
        myG2.addEdge(2, 3);
        myG2.addEdge(3, 1);

        String outContext2 = myG2.toString();
        System.out.println("myG2:");
        System.out.print(outContext2);

        System.out.println("myG2 is Bipartite:");
        TwoColor myTwoColor2 = new TwoColor(myG2);
        System.out.println(myTwoColor2.isBipartite());

    }
}
