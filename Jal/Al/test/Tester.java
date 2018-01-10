package test;

import C2.U1.Date;
import C2.U3.Quick3way;
import java.util.*;

public class Tester {
    public static void main(String[] args)
    {
        Date[] dat = new Date[]{new Date(1, 1, 2010),
        new Date(1, 1, 2017), new Date(1, 1, 2015)};
        Quick3way.sort(dat);
        for(int i = 0; i < 3; i++)
        {
            System.out.println(dat[i]);
        }
    }
}
