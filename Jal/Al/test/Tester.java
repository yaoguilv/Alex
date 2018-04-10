package test;

import C4.U2.Digraph;
import C1.Unit3_Stacks.Stack;
import C4.U2.DirectedCycle;

public class Tester {
    public static void main(String[] args)
    {
        Digraph G = new Digraph(args[0]);
        DirectedCycle myCycle = new DirectedCycle(G);
        StdLib.StdOut.println(myCycle.hasCycle());
        Stack<Integer> myStack = (Stack<Integer>)myCycle.cycle();
        while(!myStack.isEmpty())
        {
            StdLib.StdOut.println(myStack.pop());
        }
    }
}
