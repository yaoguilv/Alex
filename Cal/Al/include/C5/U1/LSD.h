#ifndef LSD_H
#define LSD_H

#include <vector>
#include <iterator>
#include <string>

using namespace std;

class LSD {
public:
    static void sort(vector<string>& a, int W)
    {
        int N = a.size();
        int R = 256;
        vector<string> aux;
        aux.reserve(N);
        for(int i = 0; i < N; i++)
        {
            string b;
            aux.push_back(b);
        }

        for(int d = W - 1; d >= 0; d--)
        {
            vector<int> count;
            count.reserve(R + 1);
            for(int i = 0; i < R + 1; i++)
                count.push_back(0);

            for(int i = 0; i < N; i++)
                count[a[i].at(d) + 1]++;

            for(int r = 0; r < R; r++)
                count[r + 1] += count[r];

            for(int i = 0; i < N; i++)
                aux[count[a[i].at(d)]++] = a[i];

            for(int i = 0; i < N; i++)
                a[i] = aux[i];
        }
    }
};

#endif
