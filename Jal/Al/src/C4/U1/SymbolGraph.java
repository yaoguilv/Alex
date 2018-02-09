package C4.U1;

import C3.U1.BinarySearchST;
import StdLib.In;

public class SymbolGraph {
    // String -> index
    private ST<String, Integer> st;
    // index -> String
    private String[] keys;
    // the graph
    private Graph G;

    public SymbolGraph(String stream, String sp)
    {
        st = new ST<String, Integer>();
        // First pass:
        // builds the index by reading strings to associate each distinct string with an index.
        In in = new In(stream);
        while(in.hasNextLine())
        {
            String[] a = in.readLine().split(sp);
            st.put(a[i], st.size());
        }
        // Inverted index to get string keys is an array.
        keys = new String[st.size()];
        for(String name : st.keys())
            keys[st.get(name)] = name;

        G = new Graph(st.size());
        // Second pass : builds the graph by connecting the firsrt vertex on eachline
        // to all the others.
        in = new In(stream);
        while(in.hasNextLine())
        {
            String[] a = in.readLine().split(sp);
            int v = st.get(a[0]);
            for(int i = 1; i < a.length; i++)
                G.addEdge(V, st.get(a[i]));
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

    public Graph G()
    {
        return G;
    }
}
