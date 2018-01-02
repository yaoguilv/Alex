package C1.Unit3_Stacks;

public class Stack<Item>
{
    private Node first; // top of stack (most recently addeed node)
    private int N;

    private class Node
    {
        // nested class to define nodes
        Item item;
        Node next;
    }

    public boolean isEmpty() { return first == null; } // Or : N == 0.
    public int size() {return N;}

    public void push(Item item)
    {
        // Add item to top of stack.
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        N++;
    }

    public Item pop()
    {
        // Remove item from top of stack.
        Item item = first.item;
        first = first.next;
        N--;
        return item;
    }

    public static void main(String[] args) {
        Stack<Integer> myStack = new Stack<Integer>();
        boolean bEmpty = myStack.isEmpty();
        System.out.println("the origin isEmpty is:");
        System.out.println(bEmpty);
        myStack.push(2);
        System.out.println("push one Integer, now the size is:");
        System.out.println(myStack.size());
        System.out.println("pop one Integer:");
        System.out.println(myStack.pop());
    }
}

