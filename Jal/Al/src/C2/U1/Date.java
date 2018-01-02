package C2.U1;

import java.util.*;

public class Date implements Comparable<Date>
{
    private final int day;
    private final int month;
    private final int year;

    public Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    public int day() { return day; }
    public int month() { return month; }
    public int year() { return year; }

    public int compareTo(Date that)
    {
        if(this.year > that.year) return +1;
        if(this.year < that.year) return -1;
        if(this.month > that.month) return +1;
        if(this.month < that.month) return -1;
        if(this.day > that.day) return +1;
        if(this.day < that.day) return -1;
        return 0;
    }

    public String toString()
    {
        return month + "/" + day + "/" + year;
    }

    public static void main(String[] args) {
        Date[] darr = new Date[3];
        darr[0] = new Date(1, 1, 2010);
        darr[1] = new Date(1, 3, 2017);
        darr[2] = new Date(1, 1, 2013);
        Arrays.sort(darr);
        for(Date d : darr)
            System.out.println(d);
    }
}
