#include "util/CDouble.h"
#include <iostream>
#include <string>
#include <sstream>
#include "C2/U1/MyDate.h"
#include "C2/U1/SortCompare.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Hello tester!" << endl;
    string alg1 = argv[1];
    string alg2 = argv[2];

    int N;
    stringstream((string)argv[3]) >> N;
    int T;
    stringstream((string)argv[4]) >> T;
    // total for alg1
    double t1 = SortCompare::timeRandomInput(alg1, N, T);
    // total for alg2
    double t2 = SortCompare::timeRandomInput(alg2, N, T);
    double ti = t2/t1;
    cout << "For " << N << " random doubles " << endl;
    cout << alg1 << " is " << ti << " times faster than " << alg2 << endl;
}

