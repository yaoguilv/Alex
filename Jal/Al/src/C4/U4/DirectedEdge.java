package C4.U4;

public class DirectedEdge {
    // edge source
    private final int v;
    // edge target
    private final int w;
    // edge weight
    private final double weight;

    public DirectedEdge(int v, int w, double weight)
    {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }

    public double weight()
    {
        return weight;
    }

    public int from()
    {
        return v;
    }

    public int to()
    {
        return w;
    }

    public String toString()
    {
        return String.format("%d->%d %.2f", v, w, weight);
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
