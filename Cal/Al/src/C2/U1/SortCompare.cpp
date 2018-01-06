#include "C2/U1/SortCompare.h"
#include <chrono>
#include <random>

double SortCompare::time(string alg, double * a, int arrLen)
{
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    if(alg.equals("Insertion")) Insertion::sort(a, arrLen);
    if(alg.equals("Selection")) Selection::sort(a, arrLen);
    chrono::system_clock::time_point end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    return elapsed_seconds.count();
}

double SortCompare::timeRandomInput(string alg, int N, int T)
{
    // Use alg to sort T random arrays of Length N.
    double total = 0.0;
    double * a = new double[N];

    random_device rd;
    default_random_engine gen(rd());
    unform_real_distribution<> disReal(2.0, 100.0);

    for(int t = 0; t < T; t++)
    {
        // Perform one experiment(generate and sort an array)
        for(int i = 0; i < N; i++)
            a[i] = disReal(gen);
        total += time(alg, a, N);
    }
    return total;
}
