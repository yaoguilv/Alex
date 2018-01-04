#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<> dis(0, 100);
    for(int i = 0; i < 10; i++)
    {
        cout << dis(gen) << endl;
    }

    cout << "-------------------" << endl;

    uniform_real_distribution<> disReal(0.0, 100.0);
    for(int i = 0; i < 10; i++)
    {
        cout << disReal(gen) << endl;
    }
    return 0;
}
