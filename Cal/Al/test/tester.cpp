#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

#include "C5/U1/MSD.h"

using namespace std;

int main(int argc, char ** argv)
{
    /* string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/words3.txt"; */
    string fileName = "/home/cx/Downloads/words3.txt";
    ifstream inputFile(fileName);
    vector<string> strArr;

    if(!inputFile.is_open())
    {
        cout << "open file failed!" << endl;
        return 0;
    }

    vector<string> a;
    for(string strIn; inputFile >> strIn; )
        a.push_back(strIn);

    int N = a.size();

    MSD::sort(a);

    for(int i = 0; i < N; i++)
        cout << a[i] << endl;

    return 0;
}
