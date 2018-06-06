#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

#include "C5/U1/LSD.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/words3.txt";
    ifstream inputFile;
    inputFile.open(fileName, fstream::in | fstream::out);
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
    int W = a[0].size();
    for(int i = 0; i < N; i++)
        if(a[i].size() != W)
        {
            cout << "Strings must have fixed length" << endl;
            return 0;
        }

    LSD::sort(a, W);

    for(int i = 0; i < N; i++)
        cout << a[i] << endl;

    return 0;
}
