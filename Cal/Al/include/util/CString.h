#ifndef CDOUBLE_H
#define CDOUBLE_H
#include "Comparable.h"
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class CString : public Comparable
{
private:
    string value;
public:
    CString(string val);
    void setValue(string val);
    string getValue();
    int compareTo(Comparable * that);
    static void split(const string& strToSplit, const string& sp, vector<string>& strArr);
};
#endif
