package C1.Unit3_Stacks;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Stack<Item> implements Iterable<Item>
{
    private Node<Item> first; // top of stack (most recently addeed node)
    private int N;

    private class Node<T>
    {
        // nested class to define nodes
        T item;
        Node<T> next;
    }

    public boolean isEmpty() { return first == null; } // Or : N == 0.
    public int size() {return N;}

    public void push(Item item)
    {
        // Add item to top of stack.
        Node<Item> oldfirst = first;
        first = new Node<Item>();
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

    public Iterator<Item> iterator() {
        return new ListIterator<Item>(first);
    }

    // an iterator, doesn't implement remove() since it's optional
    @SuppressWarnings (value="hiding")
    private class ListIterator<Item> implements Iterator<Item> {
        private Node<Item> current;

        public ListIterator(Node<Item> first) {
            current = first;
        }

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;
            return item;
        }
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

