package Chapter1_Fundamentals.Unit3_Stacks;

public class Queue<Item>
{
    private Node first;
    private Node last;
    private int N;

    private class Node
    {
        // nested class to define nodes
        Item item;
        Node next;
    }

    public boolean isEmpty() { return first == null; }
    public int size() {return N;}

    public void enqueue(Item item)
    {
        // Add item to the end of the list.
        Node oldlast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if(isEmpty()) first = last;
        else oldlast.next = last;
        N++;
    }

    public Item dequeue()
    {
        // Remove item from the beginning of the list.
        Item item = first.item;
        first = first.next;
        if(isEmpty()) last = null;
        N--;
        return item;
    }

    public static void main(String[] args) {
        Queue<Integer> ti = new Queue<Integer>();
        System.out.println("the size of init queue is:");
        System.out.println(ti.size());
        System.out.println("enqueue one int 2:");
        ti.enqueue(2);
        System.out.println("now the size of queue is:");
        System.out.println(ti.size());
        System.out.println("dequeue one int:");
        System.out.println(ti.dequeue());
    }
}

