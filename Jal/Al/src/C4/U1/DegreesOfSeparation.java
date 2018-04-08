package C4.U1;

public class DegreesOfSeparation {
    public static void main(String[] args)
    {
        SymbolGraph sg = new SymbolGraph(args[0], args[1]);
        Graph G = sg.G();

        String source = args[2];
        if(!sg.contains(source))
        {
            StdLib.StdOut.println(source + " not in database.");
            return;
        }

        int s = sg.index(source);
        BreadthFirstPaths bfs = new BreadthFirstPaths(G, s);

        while(!StdLib.StdIn.isEmpty())
        {
            String sink = StdLib.StdIn.readLine();
            if(sg.contains(sink))
            {
                int t = sg.index(sink);
                if(bfs.hasPathTo(t))
                    for(int v : bfs.pathTo(t))
                        StdLib.StdOut.println("   " + sg.name(v));
                else
                    StdLib.StdOut.println("Not in databse.");
            }
        }
    }
}
