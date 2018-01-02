package C1.Unit3_Stacks;

public class FixedCapacityStackOfStrings
{
    // stack entries
    private String[] a;
    // size
    private int N;

    public FixedCapacityStackOfStrings(int cap)
    {
        a = new String[cap];
    }

    public boolean isEmpty()
    {
        return N == 0;
    }

    public int size()
    {
        return N;
    }

    public void push(String item)
    {
        a[N++] = item;
    }

    public String pop()
    {
        return a[--N];
    }

    public static void main(String[] args) {
        FixedCapacityStackOfStrings s;
        s = new FixedCapacityStackOfStrings(100);
        StdLib.StdOut.println("please input int to stack(0 to exit, -1 to pop one int):");
        String item = StdLib.StdIn.readString();
        while(Integer.parseInt(item) != 0)
        {
            if(Integer.parseInt(item) != -1)
                s.push(item);
            else
                StdLib.StdOut.print(s.pop() + " ");
            item = StdLib.StdIn.readString();
        }
        StdLib.StdOut.println("(" + s.size() + " left on stack)");
    }
}
