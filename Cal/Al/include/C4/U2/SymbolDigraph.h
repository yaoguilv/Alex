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
                int sperateIndex = strToSplit.find(sp);
                if(string::npos != sperateIndex)
                {
                    string strOne = strToSplit.substr(0, sperateIndex);
                    string strTwo = strToSplit.substr(sperateIndex + 1);
                    MyString * pStrOne = new MyString(strOne);
                    MyString * pStrTwo = new MyString(strTwo);
                    if(!st->contains(pStrOne))
                        st->put(pStrOne, new MyInt(st->size()));
                    if(!st->contains(pStrTwo))
                        st->put(pStrTwo, new MyInt(st->size()));
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
            cout << pStr << endl;
            cout << pStr->getStr() << endl;
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
                int sperateIndex = strToSplit.find(sp);
                if(string::npos != sperateIndex)
                {
                    string strOne = strToSplit.substr(0, sperateIndex);
                    string strTwo = strToSplit.substr(sperateIndex + 1);
                    MyString * pStrOne = new MyString(strOne);
                    MyString * pStrTwo = new MyString(strTwo);
                    G->addEdge(st->get(pStrOne)->getInt(), st->get(pStrTwo)->getInt());
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
