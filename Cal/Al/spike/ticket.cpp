#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    /* string fileName = "/home/cx/Downloads/words3_4.txt"; */
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/words3_4.txt";
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

    for(vector<string>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << endl;

    return 0;
}
