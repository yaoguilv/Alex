#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

class Alphabet {

    private:
        vector<char> alphabet;
        vector<int> inverse;
        int R;
    public:
        Alphabet(string alpha)
        {
            vector<bool> unicode;
            int alLen = numeric_limits<char16_t>::max();
            unicode.reserve(alLen);
            for(int i = 0; i < alLen; i++)
            {
                alLen.push_back(false);
            }
            for(int i = 0; i < alpha.size(); i++)
            {
                char c = alpha.at(i);
                unicode[c] = true;
            }

            alphabet = alpha
        }
};

#endif
