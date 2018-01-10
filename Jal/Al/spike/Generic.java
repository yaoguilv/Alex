package spike;

import java.util.*;

class A<T>
{
    public T m;
    public A(T a)
    {
        m = a;
    }

    public T getM()
    {
        return m;
    }
}

public class Ticket {
    public static void main(String[] args)
    {
        A<Integer> myA = new A<Integer>(2);
        System.out.println(myA.getM());
    }
}
