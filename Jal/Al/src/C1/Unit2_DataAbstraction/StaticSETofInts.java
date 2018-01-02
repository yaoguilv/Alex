package C1.Unit2_DataAbstraction;

import java.util.Arrays;

public class StaticSETofInts
{
    private int[] a;

    public StaticSETofInts(int[] keys)
    {
        a = new int[keys.length];
        for(int i = 0; i < keys.length; i++)
            a[i] = keys[i];
        Arrays.sort(a);
    }

    public boolean contains(int key)
    {
        return rank(key) != -1;
    }

    private int rank(int key)
    {
        // Binary search.
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi)
        {
            // key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            if(key < a[mid])
                hi = mid - 1;
            else if (key > a[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] w = {3,2,5,1,4};
        StaticSETofInts set = new StaticSETofInts(w);
        StdLib.StdOut.println("please input the key to find(0 to exit):\n");
        int key = StdLib.StdIn.readInt();
        while(0 != key)
        {
            // Read key, print if not in whitelist.
            if(set.contains(key) == false)
                StdLib.StdOut.println("can not find the key\n");
            else
                StdLib.StdOut.println("find the key\n");
            key = StdLib.StdIn.readInt();
        }
    }

}
