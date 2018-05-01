package spike;

class GenA<T>
{
    public T m;
    public GenA(T a)
    {
        m = a;
    }

    public T getM()
    {
        return m;
    }

    public static void main(String[] args)
    {
        GenA<Integer> myGenA = new GenA<Integer>(2);
        System.out.println(myGenA.getM());
    }

}
