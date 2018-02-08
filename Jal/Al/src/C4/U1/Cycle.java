package C4.U1;

public class Cycle {
    private boolean[] marked;
    private boolean hasCycle;

    public Cycle(Graph G)
    {
        marked = new boolean[G.V()];
        for(int s = 0; s < G.V(); s++)
            if(!marked[s])
                dfs(G, s, s);
    }

    private void dfs(Graph G, int v, int u)
    {
        marked[v] = true;
        for(int w : G.adj(v))
            if(!marked[w])
                dfs(G, w, v);
            else
                if(w != u) hasCycle = true;
    }

    public boolean hasCycle()
    {
        return hasCycle;
    }

    public static void main(String[] args)
    {
        Graph myG = new Graph(5);
        myG.addEdge(0, 1);
        myG.addEdge(0, 2);
        myG.addEdge(0, 3);
        myG.addEdge(2, 3);

        Graph myG2 = new Graph(5);
        myG2.addEdge(0, 1);
        myG2.addEdge(0, 2);
        myG2.addEdge(0, 3);

        String outContext = myG.toString();
        System.out.println("myG:");
        System.out.print(outContext);

        System.out.println("myG has Cycle:");
        Cycle myCycle = new Cycle(myG);
        System.out.println(myCycle.hasCycle());

        System.out.println();

        String outContext2 = myG2.toString();
        System.out.println("myG2:");
        System.out.print(outContext2);

        System.out.println("myG2 has Cycle:");
        Cycle myCycle2 = new Cycle(myG2);
        System.out.println(myCycle2.hasCycle());

    }

}
