package C1.Unit3_Stacks;

import java.util.Iterator;

public class Bag<Item> implements Iterable<Item>
{

    private Node first;

    private class Node
    {
        Item item;
        Node next;
    }

    public void add(Item item)
    {
        // same as push() in Stack
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
    }

    public Iterator<Item> iterator()
    {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item>
    {
        private Node current = first;

        public boolean hasNext()
        {
            return current != null;
        }

        public void remove() {}

        public Item next()
        {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

   public static void main(String[] args) {
        Bag<Integer> ti = new Bag<Integer>();
        System.out.println("addd one int to bag: 2:");
        ti.add(2);
        Iterator<Integer> it = ti.iterator();

        System.out.println("now the bag has next:");
        System.out.println(it.hasNext());
        System.out.println("next element of bag is:");
        System.out.println(it.next());
    }
}

