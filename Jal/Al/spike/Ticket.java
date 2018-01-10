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

class MyDate implements Comparable<MyDate>
{
    public int N;
    public MyDate(int n)
    {
        N = n;
    }

    public int compareTo(MyDate that)
    {
        return 1;
    }

    public int getN()
    {
        return N;
    }
}

public class Ticket {
    public static void main(String[] args)
    {
        A<?>[] myA = new A<?>[3];
        myA[0] = new A<Integer>(11);
        myA[1] = new A<Integer>(12);
        myA[2] = new A<Integer>(13);
        @SuppressWarnings("unchecked")
        A<Integer> d = (A<Integer>)myA[0];
        // above codes: A<Interger> can been see as a child of A<?> (like C++ generation)
        // java annotation "unchecked" is just like dynamic_cast in C++
        System.out.println(d.m);

        /* --------------------------------------------------------------------*/
        /* more examples: */
        Comparable<?>[] myD = new Comparable<?>[3];
        myD[0] = new MyDate(2012);
        @SuppressWarnings("unchecked")
        MyDate myDD = (MyDate)myD[0];
        // above codes: MyDate is a child of Comparable<MyDate>, Comparable<MyDate> is a child of Comparable<?>
        System.out.println(myDD.N);
    }
}
