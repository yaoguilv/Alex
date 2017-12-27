package spike;

import java.util.Comparator;

public class Ticket {
    public static void main(String[] args) {
        int item = StdLib.StdIn.readInt();
        while(0 != item)
        {
            StdLib.StdOut.print(">>>");
            StdLib.StdOut.print(item);
            item = StdLib.StdIn.readInt();
        }
    }
}
