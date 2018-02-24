package test;

import java.util.*;
import C4.U1.Graph;
import C4.U1.TwoColor;
import C4.U1.SymbolGraph;

public class Tester {
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
