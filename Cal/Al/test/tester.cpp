#include <iostream>

using namespace std;

int main()
{
}
#include "C2/U1/Date.h"
    public static void main(String[] args) {
        Date[] darr = new Date[3];
        darr[0] = new Date(1, 1, 2010);
        darr[1] = new Date(1, 3, 2017);
        darr[2] = new Date(1, 1, 2013);
        Arrays.sort(darr);
        for(Date d : darr)
            System.out.println(d);
    }

