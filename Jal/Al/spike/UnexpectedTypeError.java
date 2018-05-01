package spike;

class MyErrorClass<Key extends Comparable<Key>, Value>
{
    public void print()
    {
        System.out.print("dd");
    }

    public static void main(String[] args) {
        MyErrorClass<Integer, Integer> myClass = new MyErrorClass<Integer, Integer>();
        // MyErrorClass<String, String> myClass2 = new MyErrorClass<String, String>();
        // below is will be error: Unexpected type   requied: reference   found:int
        // MyClass<int, int> myClass = new MyClass<int, int>();

        myClass.print();
    }

}

