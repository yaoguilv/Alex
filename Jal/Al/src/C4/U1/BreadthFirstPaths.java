package C4.U1;

import java.util.*;
import C4.U1.Graph;
import C1.Unit3_Stacks.Stack;

public class BreadthFirstPaths {
    // Is a shortest path to this vertex known?
    private boolean[] marked;
    // last vertex on known path to this vertex
    private int[] edgeTo;
    // source
    private final int s;

    public BreadthFirstPaths(Graph G, int s)
    {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        bfs(G, s);
    }

    private void bfs(Graph G, int s)
    {
        Queue<Integer> queue = new LinkedList<Integer>();
        // Mark the source
        marked[s] = true;
        // and put it on the queue.
        queue.add(s);
        while(0 != queue.size())
        {
            // Remove next vertex from the queue.
            int v = queue.remove();
            for(int w : G.adj(v))
                // for every unmarked adjacent vertex.
                if(!marked[w])
                {
                    // save last edge on a shortest path.
                    edgeTo[w] = v;
                    // mark it because path is known.
                    marked[w] = true;
                    // and add it to the queue.
                    queue.add(w);
                }
        }
    }

    public boolean hasPathTo(int v)
    {
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v)
    {
        if(!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<Integer>();
        for(int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }

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
        BreadthFirstPaths search = new BreadthFirstPaths(myG, s);
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
