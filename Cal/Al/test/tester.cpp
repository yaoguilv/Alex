#include <iostream>
#include "C2/U1/Insertion.h"
#include "C2/U1/Selection.h"
#include "C2/U1/MyDate.h"
#include "C2/U1/SortCompare.h

using namespace std;

int main()
{
    cout << "Hello tester!" << endl;
    string alg1 = args[0];
    string alg2 = args[1];
    int N = Integer.parseInt(args[2]);
    int T = Integer.parseInt(args[3]);
    double t1 = SortCompare::timeRandomInput(alg1, N, T); // total for alg1
    double t2 = SortCompare::timeRandomInput(alg2, N, T); // total for alg2
    double ti = t2/t1;
    cout << "For " << N << " random doubles " << endl;
    cout << alg1 << " is " << ti <<  << "times faster than " << alg2 << endl;
    StdLib.StdOut.printf("For %d random Doubles\n      %s is", N, alg1);
    StdLib.StdOut.printf(" %.1f times faster than %s\n", t2/t1, alg2);

}

