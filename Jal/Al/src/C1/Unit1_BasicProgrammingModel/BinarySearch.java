package C1.Unit1_BasicProgrammingModel;

import java.util.Arrays;

public class BinarySearch
{
    public static int rank(int key, int[] a)
    {
        //Array must be sorted.
        int lo = 0;
        int hi = a.length - 1;
        while(lo <= hi)
        {
            //Key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            if(key < a[mid])
                hi = mid - 1;
            else if(key > a[mid])
                lo= mid + 1;
            else
                return mid;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] whitelist = {2,1,5,3,4,8,6,7};

        Arrays.sort(whitelist);

        StdLib.StdOut.print("please enter a int to find(enter 0 to exit):\n");

        int key = StdLib.StdIn.readInt();
        while(0 != key)
        {
            // Read key, print if not in whitelist.
            if(BinarySearch.rank(key, whitelist) > 0)
                StdLib.StdOut.print("found\n");
            else
                StdLib.StdOut.print("not found\n");
            key = StdLib.StdIn.readInt();
        }
    }

}
