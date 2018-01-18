package test;

import java.util.*;
import C3.U4.SeparateChainingHashST;

public class Tester {
    public static void main(String[] args)
    {
        SeparateChainingHashST<Integer, String> mySCH = new SeparateChainingHashST<Integer, String>();

        mySCH.put(1, "aaa");
        mySCH.put(3, "ccc");
        mySCH.put(2, "bbb");

        System.out.println("get 2:");
        System.out.println(mySCH.get(2));

        System.out.println("get 1:");
        System.out.println(mySCH.get(1));

        System.out.println("get 3:");
        System.out.println(mySCH.get(3));

    }
}
