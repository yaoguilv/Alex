package spike;

import java.util.*;

class B
{
    public int n;
}

public class Ticket {
    public static void main(String[] args)
    {
        B[] myB = new B[3];
        myB[0] = new B();
        myB[1] = new B();
        myB[2] = new B();
        myB[0].n = 3;
        myB[1].n = 2;
        myB[2].n = 1;

        for(int i = 0; i < 3; i++)
        {
            System.out.println(myB[i].n);
        }
    }
}
