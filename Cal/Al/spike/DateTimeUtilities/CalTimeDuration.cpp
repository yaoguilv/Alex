#include <iostream>
#include <chrono>

using namespace std;

long fibonacci(unsigned n)
{
    if(n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    cout << "f(42) = " << fibonacci(42) << endl;
    // below code is equal to : chrono::time_point<chrono::system_clock>
    chrono::system_clock::time_point end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "elapsed time : " << elapsed_seconds.count() << endl;
    return 0;
}
