package C4.U2;

import C4.U2.Digraph;
import C4.U2.DirectedCycle;
import C4.U2.DepthFirstOrder;

public class Topological {
    private Iterable<Integer> order; // topological order

    public Topological(Digraph G)
    {
        DirectedCycle cyclefinder = new DirectedCycle(G);
        if(!cyclefinder.hasCycle())
        {
            DepthFirstOrder dfs = new DepthFirstOrder(G);
            order = dfs.reversePost();
        }
    }

    public Iterable<Integer> order()
    {
        return order;
    }

    public boolean isDAG()
    {
        return null == order;
    }

}
