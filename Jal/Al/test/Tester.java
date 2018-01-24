package test;

import java.util.*;
import C4.U1.Graph;
import C4.U1.BreadthFirstPaths;

public class Tester {
    public static void main(String[] args)
    {
        Graph myG = new Graph(7);
        myG.addEdge(0, 1);
        myG.addEdge(0, 2);
        myG.addEdge(0, 5);
        myG.addEdge(0, 6);
        myG.addEdge(5, 3);
        myG.addEdge(5, 4);
        myG.addEdge(3, 4);
        myG.addEdge(4, 6);
        String outContext = myG.toString();
        System.out.print(outContext);

        int s = 0;
        DepthFirstPaths search = new DepthFirstPaths(myG, s);
        for(int v = 0; v < myG.V(); v++)
        {
            StdLib.StdOut.print(s + " to " + v + ": ");
            if(search.hasPathTo(v))
                for(int x : search.pathTo(v))
                    if(x == s) StdLib.StdOut.print(x);
                    else StdLib.StdOut.print("-" + x);
            StdLib.StdOut.println();
        }
    }
}
