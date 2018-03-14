#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <chrono>

using namespace std;
using namespace chrono;

int fibonacci(int n)
{
    if(n < 2)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n -2);
}

int main(int argc, char ** argv)
{
    system_clock::time_point start = system_clock::now();
    fibonacci(42);
    system_clock::time_point end = system_clock::now();
    duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << endl;

    return 0;
}
