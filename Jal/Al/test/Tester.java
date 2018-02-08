package test;

import java.util.*;
import C4.U1.Graph;
import C4.U1.Cycle;

public class Tester {
    public static void main(String[] args)
    {
        Graph myG = new Graph(5);
        // myG.addEdge(0, 1);
        // myG.addEdge(0, 2);
        // myG.addEdge(0, 5);
        // myG.addEdge(0, 6);
        // myG.addEdge(5, 3);
        // myG.addEdge(5, 4);
        // myG.addEdge(3, 4);
        // myG.addEdge(4, 6);
        // myG.addEdge(7, 8);
        // myG.addEdge(9, 10);
        // myG.addEdge(9, 11);
        // myG.addEdge(9, 12);
        // myG.addEdge(11, 12);
        myG.addEdge(0, 1);
        myG.addEdge(0, 2);
        myG.addEdge(0, 3);
        myG.addEdge(2, 3);

        Graph myG2 = new Graph(5);
        myG2.addEdge(0, 1);
        myG2.addEdge(0, 2);
        myG2.addEdge(0, 3);

        String outContext = myG.toString();
        System.out.println("myG:");
        System.out.print(outContext);

        System.out.println("myG has Cycle:");
        Cycle myCycle = new Cycle(myG);
        System.out.println(myCycle.hasCycle());

        System.out.println();

        String outContext2 = myG2.toString();
        System.out.println("myG2:");
        System.out.print(outContext2);

        System.out.println("myG2 has Cycle:");
        Cycle myCycle2 = new Cycle(myG2);
        System.out.println(myCycle2.hasCycle());

    }
}
