#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "C5/U1/Alphabet.h"

using namespace std;

int main(int argc, char ** argv)
{
    string strIn = "ABCDR";
    Alphabet* alpha = new Alphabet(strIn);
    int R = alpha->getR();
    vector<int> countAlpha;
    countAlpha.reserve(R);
    for(int i = 0; i < R; i++)
        countAlpha.push_back(0);

    string strAnalysis = "ABRACADABRA";
    int N = strAnalysis.size();
    for(int i = 0; i < N; i++)
        if(alpha->contains(strAnalysis[i]))
            countAlpha[alpha->toIndex(strAnalysis[i])]++;

    for(int c = 0; c < R; c++)
        cout << alpha->toChar(c) << " " << countAlpha[c] << endl;
    return 0;
}
