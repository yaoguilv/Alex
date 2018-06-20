#ifndef MSD_H
#define MSD_H

#include <vector>
#include <string>

using namespace std;

class MSD {
private:
    const int R = 256;
    const int M = 125;
    vector<string> aux;

    int charAt(string s, int d);
    void sort(vector<string>& a, int lo, int hi, int d);
    void insertion(vector<string>& a, int lo, int hi, int d);
    void exch(vector<string>& a, int i, int j);
    bool less(string v, string w, int d);

public:
    void sort(vector<string>& a);
};

#endif
