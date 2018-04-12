package C4.U2;

import C4.U2.Digraph;
import C3.U1.SequentialSearchST;
import StdLib.In;

public class SymbolDigraph {
    // String -> index
    private SequentialSearchST<String, Integer> st;
    // index -> String
    private String[] keys;
    // the graph
    private Digraph G;

    public SymbolDigraph(String stream, String sp)
    {
        st = new SequentialSearchST<String, Integer>();
        // First pass;
        // builds the index by reading strings to associate
        // each distinct string with an index
        In in = new In(stream);
        while(in.hasNextLine())
        {
            String[] a = in.readLine().split(sp);
            for(int i = 0; i < a.length; i++)
                if(!st.contains(a[i]))
                    st.put(a[i], st.size());
        }
        // Inverted index to get string keys is an array.
        keys = new String[st.size()];
        for(String name : st.keys())
            keys[st.get(name)] = name;

        G = new Digraph(st.size());
        // second pas : builds the graph by connecting the
        // first vertex on eachline
        // to all the others
        in = new In(stream);
        while(in.hasNextLine())
        {
            String[] a = in.readLine().split(sp);
            int v = st.get(a[0]);
            for(int i = 1; i < a.length; i++)
                G.addEdge(v, st.get(a[i]));
        }
    }

    public boolean contains(String s)
    {
        return st.contains(s);
    }

    public int index(String s)
    {
        return st.get(s);
    }

    public String name(int v)
    {
        return keys[v];
    }

    public Digraph G()
    {
        return G;
    }
}
