#ifndef SYMBOLDIGRAPH_H
#define SYMBOLDIGRAPH_H

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "C4/U2/Digraph.h"
#include "C3/U1/SequentialSearchST.h"
#include "C2/U1/MyString.h"
#include "C2/U1/MyInt.h"
#include "util/CString.h"

using namespace std;

class SymbolDigraph {
private:
    // String -> index
    SequentialSearchST<MyString *, MyInt *> * st;
    // index -> string
    MyString ** keys;
    // the graph
    Digraph * G;

public:
    SymbolDigraph(const string& fileName, const string& sp)
    {
        st = new SequentialSearchST<MyString *, MyInt *>();
        // First pass:
        // builds the index by reading strings to associate each distinct string with an index.
        char buf[256];
        ifstream inputFile;
        inputFile.open(fileName, fstream::in | fstream::out);
        if(!inputFile.is_open())
            cout << "open failed!" << endl;
        else
        {
            while(!inputFile.eof())
            {
                inputFile.getline(buf, 100);
                string strToSplit = buf;
                if(!strToSplit.empty())
                {
                    vector<string> strArr;
                    CString::split(strToSplit, sp, strArr);
                    for(vector<string>::iterator it = strArr.begin(); it != strArr.end(); it++)
                    {
                        MyString* pStr = new MyString(*it);
                        if(!st->contains(pStr))
                        {
                            st->put(pStr, new MyInt(st->size()));
                        }
                    }
                }
            }
            inputFile.close();
        }

        // Inverted index to get string keys is an array.
        vector<MyString*> inKeys;
        st->getKeys(inKeys);
        MyString * outKeys[st->size()];
        keys = outKeys;
        for(int i = 0; i < st->size(); i++)
        {
            MyString * pStr = inKeys[i];
            MyInt * pInt = st->get(pStr);
            outKeys[pInt->getInt()] = pStr;
        }

        G = new Digraph(st->size());

        // second pass : builds the graph by connecting the first vertex on eachline
        // to all the others.
        inputFile.open(fileName, fstream::out | fstream::in);
        if(!inputFile.is_open())
            cout << "open failed!" << endl;
        else
        {
            while(!inputFile.eof())
            {
                inputFile.getline(buf, 100);
                string strToSplit = buf;
                vector<string> strArr;
                CString::split(strToSplit, sp, strArr);
                for(int i = 1; i < strArr.size(); i++)
                {
                    G->addEdge(st->get(new MyString(strArr[0]))->getInt(), st->get(new MyString(strArr[i]))->getInt());
                }
            }
            inputFile.close();
        }
    }

    bool contains(string s)
    {
        MyString * pS = new MyString(s);
        return st->contains(pS);
    }

    int index(string s)
    {
        MyString * pS = new MyString(s);
        return st->get(pS)->getInt();
    }

    string name(int v)
    {
        return keys[v]->getStr();
    }

    Digraph * getG()
    {
        return G;
    }

};

#endif
