package spike;

class GenericArrayA<T>
{
    public T m;
    public GenericArrayA(T a)
    {
        m = a;
    }

    public T getM()
    {
        return m;
    }
}

class GenericArrayB
{
    public int n;

    public static void main(String[] args) {
        GenericArrayA<Integer> myA = new GenericArrayA<Integer>(2);
        System.out.println(myA.getM());

        GenericArrayB[] myB = new GenericArrayB[3];
        myB[0] = new GenericArrayB();
        myB[1] = new GenericArrayB();
        myB[2] = new GenericArrayB();
        myB[0].n = 3;
        myB[1].n = 2;
        myB[2].n = 1;

        for(int i = 0; i < 3; i++)
        {
            System.out.println(myB[i].n);
        }

        GenericArrayA<?>[] myAAA = new GenericArrayA<?>[3];
        @SuppressWarnings("unchecked")
        GenericArrayA<Integer> d = (GenericArrayA<Integer>)myAAA[0];
        System.out.println(d.m);
 }

}
