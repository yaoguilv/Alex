package spike;

import java.util.Comparator;

class MyClass<Key extends Comparable<Key>, Value>
{
    public void print()
    {
        System.out.print("dd");
    }

    public static void main(String[] args) {
        MyClass<Integer, Integer> myClass = new MyClass<Integer, Integer>();
        MyClass<String, String> myClass2 = new MyClass<String, String>();
        // below is will be error: Unexpected type   requied: reference   found:int
        // MyClass<int, int> myClass = new MyClass<int, int>();

        myClass.print();
    }

}


