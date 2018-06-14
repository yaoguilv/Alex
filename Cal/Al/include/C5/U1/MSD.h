#ifndef MSD_H
#define MSD_H

#include <vector>
#include <string>

using namespace std;

class MSD {
private:

    static int charAt(string s, int d);

    static void sort(vector<string>& a, int lo, int hi, int d);

    static void insertion(vector<string>& a, int lo, int hi, int d);

    static void exch(vector<string>& a, int i, int j);

    static bool less(string v, string w, int d);

public:

    static void sort(vector<string>& a);
};

#endif
