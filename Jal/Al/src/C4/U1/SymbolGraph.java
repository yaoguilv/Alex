package C4.U1;

import C4.U1.Graph;
import C3.U1.SequentialSearchST;
import StdLib.In;

public class SymbolGraph {
    // String -> index
    private SequentialSearchST<String, Integer> st;
    // index -> String
    private String[] keys;
    // the graph
    private Graph G;

    public SymbolGraph(String stream, String sp)
    {
        st = new SequentialSearchST<String, Integer>();
        // First pass:
        // builds the index by reading strings to associate
        // each distinct string with an index.
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

        G = new Graph(st.size());
        // Second pass : builds the graph by connecting the
        // firsrt vertex on eachline
        // to all the others.
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

    public Graph G()
    {
        return G;
    }

/******************************************************************************
 *  Compilation:  javac SymbolGraph.java
 *  Execution:    java SymbolGraph filename.txt delimiter
 *  Dependencies: ST.java Graph.java In.java StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/41graph/routes.txt
 *
 *  %  java SymbolGraph routes.txt " "
 *  JFK
 *     MCO
 *     ATL
 *     ORD
 *  LAX
 *     PHX
 *     LAS
 *
 *  Assumes that input file is encoded using UTF-8.
 *  % iconv -f ISO-8859-1 -t UTF-8 movies-iso8859.txt > movies.txt
 *
 ******************************************************************************/

    public static void main(String[] args)
    {
        String filename = args[0];
        String delim = args[1];
        SymbolGraph sg = new SymbolGraph(filename, delim);

        Graph G = sg.G();

        while(StdLib.StdIn.hasNextLine())
        {
            String source = StdLib.StdIn.readLine();
            for(int w : G.adj(sg.index(source)))
                StdLib.StdOut.println("  " + sg.name(w));
        }
    }

}
