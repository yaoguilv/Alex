package C4.U2;

import java.util.ArrayList;
import C4.U1.Graph;
import C3.U1.SequentialSearchST;
import StdLib.In;
import C1.Unit3_Stacks.Bag;

public class Digraph {
    private final int V;
    private int E;
    private Bag<Integer>[] adj;

    // build Digraph using file, elements in file separate with " "(space character)
    @SuppressWarnings("unchecked")
    public Digraph(String stream)
    {
        String sp = " ";
        ArrayList<Integer> myArr = new ArrayList<Integer>();

        In in = new In(stream);
        while(in.hasNextLine())
        {
            String[] a = in.readLine().split(sp);
            for(int i = 0; i < a.length; i++)
                if(!myArr.contains(Integer.parseInt(a[i])))
                    myArr.add(Integer.parseInt(a[i]));
        }

        this.V = myArr.size();
        this.E = 0;
        adj = (Bag<Integer>[]) new Bag<?>[V];
        for(int i = 0; i < V; i++)
            adj[i] = new Bag<Integer>();
        // Second pass : builds the graph by connecting the firsrt vertex on eachline
        // to all the others.
        in = new In(stream);
        while(in.hasNextLine())
        {
            String[] a = in.readLine().split(sp);
            addEdge(Integer.parseInt(a[0]), Integer.parseInt(a[1]));
        }
    }

    @SuppressWarnings("unchecked")
    public Digraph(int v)
    {
        this.V = v;
        this.E = 0;
        adj = (Bag<Integer>[]) new Bag<?>[V];
        for(int i = 0; i < V; i++)
            adj[i] = new Bag<Integer>();
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
        adj[v].add(w);
        E++;
    }

    public Iterable<Integer> adj(int v)
    {
        return adj[v];
    }

    public Digraph reverse()
    {
        Digraph R = new Digraph(V);
        for(int v = 0; v < V; v++)
            for(int w : adj(v))
                R.addEdge(w, v);
        return R;
    }
}
