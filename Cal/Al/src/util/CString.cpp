#include "util/CString.h"

using namespace std;

CString::CString(string val)
{
    this->value = val;
}

void CString::setValue(string val)
{
    this->value = val;
}

int CString::compareTo(Comparable * that)
{
    CString * thatCString = dynamic_cast<CString *>(that);
    if(this->value > thatCString->value)
    {
        return 1;
    }
    else if(this->value < thatCString->value)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

string CString::getValue()
{
    return this->value;
}

void CString::split(const string& strToSplit, const string& sp, vector<string>& strArr)
{
    int nowPos = 0;
    while(string::npos != strToSplit.find(sp, nowPos))
    {
        int spPos = strToSplit.find(sp, nowPos);
        strArr.push_back(strToSplit.substr(nowPos, spPos - nowPos));
        nowPos = spPos + 1;
    }
    strArr.push_back(strToSplit.substr(nowPos, strToSplit.size() - nowPos));
}
