#include <iostream>
#include <string>
#include "C4/U2/Digraph.h"
#include "C4/U2/KosarajuSCC.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/tinyDG.txt";
    Digraph* dg = new Digraph(fileName);

    KosarajuSCC* ks = new KosarajuSCC(dg);

    cout << ks->count() << endl;

    for(int i = 0; i < ks->count(); i++)
    {
        for(int j = 0; j < dg->getV(); j++)
        {
            if(ks->id(j) == i)
                cout << j << "  ";
        }
        cout << endl;
    }
}
