#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>
#include <iterator>
#include <string>
#include <limits>
#include <string>

using namespace std;

class Alphabet {

    private:
        vector<char> alphabet;
        vector<int> inverse;
        int R;

        Alphabet(int R)
        {
            alphabet.reserve(R);
            inverse.reserve(R);
            this->R = R;

            for(int i = 0; i < R; i++)
            {
                alphabet.push_back(0);
                inverse.push_back(-1);
            }
            for(int i = 0; i < R; i++)
                alphabet[i] = (char)i;
            for(int i = 0; i < R; i++)
                inverse[i] = i;
        }

    public:
        Alphabet(string alpha)
        {
            vector<bool> unicode;
            int alLen = numeric_limits<char16_t>::max();
            unicode.reserve(alLen);
            inverse.reserve(alLen);
            for(int i = 0; i < alLen; i++)
            {
                unicode.push_back(false);
                inverse.push_back(-1);
            }
            for(int i = 0; i < alpha.size(); i++)
            {
                char c = alpha.at(i);
                unicode[c] = true;
            }

            alphabet.assign(alpha.begin(), alpha.end());
            R = alpha.size();

            for(int c = 0; c < R; c++)
                inverse[alphabet[c]] = c;
        }

        Alphabet() : Alphabet(256)
        {
        }

        bool contains(char c)
        {
            return inverse[c] != -1;
        }

        int getR()
        {
            return R;
        }

        int lgR()
        {
            int lgR = 0;
            for(int t = R; t > 1; t /=2)
                lgR++;
            return lgR;
        }

        int toIndex(char c)
        {
            return inverse[c];
        }

        void toIndices(string s, vector<int>& target)
        {
            vector<char> source(s.begin(), s.end());
            for(int i = 0; i < source.size(); i++)
                target.push_back(toIndex(source[i]));
        }

        char toChar(int index)
        {
            return alphabet[index];
        }

        string toChars(vector<int>& indices)
        {
            string s;
            for(int i = 0; i < indices.size(); i++)
                s.push_back(toChar(indices[i]));
            return s;
        }
};

#endif
