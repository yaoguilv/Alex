#include "C5/U1/MSD.h"

int MSD::charAt(string s, int d)
{
    if(d < s.size())
        return s.at(d);
    else
        return -1;
}

void MSD::sort(vector<string>& a, int lo, int hi, int d)
{
    if(hi <= lo + M)
    {
        insertion(a, lo, hi, d);
        return;
    }

    vector<int> count;
    count.reserve(R + 2);
    for(int i = 0; i < R + 2; i++)
        count.push_back(0);
    for(int i = lo; i <= hi; i++)
        count[charAt(a[i], d) + 2]++;

    for(int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];

    for(int i = lo; i <= hi; i++)
        aux[count[charAt(a[i], d) + 1]++] = a[i];

    // Copy back
    for(int i = lo; i <= hi; i++)
        a[i] = aux[i - lo];

    // Recursively sort for each character value.
    for(int r = 0; r < R; r++)
        sort(a, lo + count[r], lo + count[r + 1] -1, d + 1);
}

// return dth character of s, -1 if d = length of string
void MSD::insertion(vector<string>& a, int lo, int hi, int d)
{
    for(int i = lo; i <= hi; i++)
        for(int j = i; j > lo && less(a[j], a[j - 1], d); j--)
            exch(a, j, j - 1);
}

// exchange a[i] and a[j]
void MSD::exch(vector<string>& a, int i, int j)
{
    string temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// is v less than w, starting at character d
bool MSD::less(string v, string w, int d)
{
    if(v.substr(d, v.size() - 1) < w.substr(d, w.size() - 1))
        return true;
    else
        return false;
}

void MSD::sort(vector<string>& a)
{
    int N = a.size();
    aux.reserve(N);
    for(int i = 0; i < N; i++)
    {
        string astr;
        aux.push_back(astr);
    }
    sort(a, 0, N - 1, 0);
}
