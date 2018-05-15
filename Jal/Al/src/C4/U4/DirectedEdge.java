package C4.U4;

import C4.U3.Edge;


public class DirectedEdge extends Edge {
    // // edge source
    // private final int v;
    // // edge target
    // private final int w;
    // // edge weight
    // private final double weight;

    public DirectedEdge(int v, int w, double weight)
    {
        super(v, w, weight);
    }

    // public double weight()
    // {
    //     return weight;
    // }

    public int from()
    {
        return super.either();
    }

    public int to()
    {
        return other(super.either());
    }

    public String toString()
    {
        return String.format("%d->%d %.2f", super.either(), super.other(super.either()), super.weight());
    }

    public static void main(String[] args)
    {
        DirectedEdge myDE = new DirectedEdge(1, 2, 5.2);

        System.out.println(myDE.weight());
        System.out.println(myDE.from());
        System.out.println(myDE.to());

        System.out.println(myDE.toString());
    }

}
