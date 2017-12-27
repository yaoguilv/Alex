package Chapter1_Fundamentals.Unit2_DataAbstraction;

public class Accumulator
{
    private double total;
    private int N;

    public void addDataValue(double val)
    {
        N++;
        total += val;
    }

    public double mean()
    {
        return total/N;
    }

    public String toString()
    {
        return "Mean (" + N + " values): " + String.format("%7.5f", mean());
    }

    public static void main(String[] args) {
        int T = 4;
        Accumulator a = new Accumulator();
        for(int t = 0; t < T; t++)
            a.addDataValue(t);
        StdLib.StdOut.println(a);
    }

}


