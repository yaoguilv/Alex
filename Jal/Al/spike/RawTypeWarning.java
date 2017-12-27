package spike;

public class Ticket {
    public static void main(String[] args) {
        // here : two <String, String>  needed!
        MyClass<String, String> myClass = new MyClass<String, String>();
        myClass.print();
    }
}

class MyClass<Key, Value>
{
    public void print()
    {
        System.out.print("dd");
    }
}

