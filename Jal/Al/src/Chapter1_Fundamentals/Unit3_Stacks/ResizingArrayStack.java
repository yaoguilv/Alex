package Chapter1_Fundamentals.Unit3_Stacks;

import java.util.Iterator;

public class ResizingArrayStack<Item> implements Iterable<Item>
{
    private Item[] a = (Item[]) new Object[1];
    private int N = 0;

    public boolean isEmpty()
    {
        return N == 0;
    }

    public int size()
    {
        return N;
    }

    private void resize(int max)
    {
        // Move stack to a new array of size max.
        Item[] temp = (Item[]) new Object[max];
        for(int i = 0; i < N; i++)
            temp[i] = a[i];
        a = temp;
    }

    public void push(Item item)
    {
        // Add item to top of stack.
        if(N == a.length) resize(2*a.length);
        a[N++] = item;
    }

    public Item pop()
    {
        // Remove item from top of stack.
        Item item = a[--N];
        a[N] = null;
        if(N > 0 && N == a.length/4) resize(a.length/2);
        return item;
    }

    public Iterator<Item> iterator()
    { return new ReverseArrayIterator(); }

    private class ReverseArrayIterator implements Iterator<Item>
    {
        // Support LIFO iteration.
        private int i = N;
        public boolean hasNext() { return i > 0; }
        public Item next() { return a[--i]; }
        public void remove() {}
    }

    public static void main(String[] args) {
        ResizingArrayStack<Integer> ras = new ResizingArrayStack<Integer>();
        boolean bEmpty = ras.isEmpty();
        System.out.println("the origin isEmpty is:");
        System.out.println(bEmpty);
        ras.push(2);
        System.out.println("push one Integer, now the size is:");
        System.out.println(ras.size());
        System.out.println("pop one Integer:");
        System.out.println(ras.pop());
    }

}
