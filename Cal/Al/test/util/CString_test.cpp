#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "C1/Unit3_Stacks/Queue.h"
#include "C1/Unit3_Stacks/Stack.h"
#include "C4/U2/SymbolDigraph.h"
#include "C4/U2/Topological.h"
#include "util/CString.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "usr/lib/.workspace/Alex/Cal/Al/data/jobs.txt";
    string delim = "/";
    vector<string> myArr;
    CString::split(fileName, delim, myArr);
    for(vector<string>::iterator it = myArr.begin(); it != myArr.end(); it++)
    {
        cout << *it << "    " << endl;
    }
}

