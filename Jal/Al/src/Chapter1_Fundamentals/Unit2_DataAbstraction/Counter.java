package Chapter1_Fundamentals.Unit2_DataAbstraction;

public class Counter
{
    private final String name;
    private int count;

    public Counter(String id)
    {
        name = id;
    }

    public void increment()
    {
        count++;
    }

    public int tally()
    {
        return count;
    }

    public String toString()
    {
        return count + " " + name;
    }

    public static void main(String[] args) {
        int T = 12;
        Counter heads = new Counter("heads");
        Counter tails = new Counter("tails");

        for(int t = 0; t < T; t++)
        {
            if(t % 3 == 0)
                heads.increment();
            else
                tails.increment();
        }

        StdLib.StdOut.println(heads);
        StdLib.StdOut.println(tails);
        int d = heads.tally() - tails.tally();
        StdLib.StdOut.println("delta: " + Math.abs(d));
    }

}
