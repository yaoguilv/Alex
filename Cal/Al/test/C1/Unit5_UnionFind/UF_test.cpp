#include <iostream>
#include "C1/U5/UF.h"

using namespace std;

int main()
{
    cout << "input the number of array to init:" << endl;
    int N;
    cin >> N;
    UF * uf = new UF(N);
    cout << "array has been initialized!" << endl;
    cout << "union the array? (0 to exit, others to continue):" << endl;
    int key;
    cin >> key;
    while(0 != key)
    {
        cout << "input int to Unit Find" << endl;
        int p, q;
        cin >> p;
        cout << "you put p:" << p << endl;
        cin >> q;
        cout << "you put q:" << q << endl;
        if(uf->connected(p, q))
        {
            cout << "already connected!";
            continue;
        }
        uf->unionF(p, q);
        cout << p << " " << q << "has been unioned" << endl;
        cout << "continue union? (0 to exit, others to continue):" << endl;
        cin >> key;
    }
    cout << uf->size() << " components" << endl;
}
