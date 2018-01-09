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

class B
{
    public int n;
}

public class Ticket
{
    public static void main(String[] args) {
        A<Integer> myA = new A<Integer>(2);
        System.out.println(myA.getM());

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

        Comprable<?>[] myAA = new Comparable<?>[3];
        A<?>[] myAAA = new A<?>[3];
        @SuppressWarnings("unchecked")
        A<Integer> d = (A<Integer>)myAAA[0];
        System.out.println(d.m);
 }
}
