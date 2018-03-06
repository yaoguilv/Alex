#ifndef SYMBOLGRAPH_H
#define SYMBOLGRAPH_H
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "C4/U1/Graph.h"

using namespace std;

class SymbolGraph {
private:
    // String -> index
    SequentialSearchST<string, int> * st;
    // index -> string
    string* keys;
    // the graph
    Graph * G;

public:
    SymbolGraph(string stream, string sp)
    {
        st = new SequentialSearchST<string, int>();
        // First pass:
        // builds the index by reading strings to associate each distinct string with an index.
        char buf[256];
        ifstream inputFile;
        inputFile.open(stream, ifstream::read);
        if(inputFile.is_open())
            cout << "open failed!" << endl;
        else
        {
            while(!inputFile.eof())
            {
                inputFile.getline(buf, 100);
                string strToSplit = buf;
                int sperateIndex = strToSplit.find(sp);
                string strOne = strToSplit.substr(0, sperateIndex);
                string strTwo = strToSplit.substr(sperateIndex);
                if(!st->contains(strOne))
                    st->put(strOne, st->size());
                if(!st->contains(strTwo))
                    st->put(strTwo, st->size());
            }
            inputFile.close();
        }

        // Inverted index to get string keys is an array.
        keys = new string[st->size];
        for(auto name : st.keys())
            keys[st->get(name)] = name;

        G = new Graph(st->size());

        // second pass : builds the graph by connecting the first vertex on eachline
        // to all the others.
        inputFile.open(stream, ifstream::read);
        if(inputFile.is_open())
            cout << "open failed!" << endl;
        else
        {
            while(!inputFile.eof())
            {
                inputFile.getline(buf, 100);
                string strToSplit = buf;
                int sperateIndex = strToSplit.find(sp);
                string strOne = strToSplit.substr(0, sperateIndex);
                string strTwo = strToSplit.substr(sperateIndex);
                G->addEdge(st->get(strOne), st->get(strTwo));
            }
            inputFile.close();
        }
    }

    bool contains(string s)
    {
        return st->contains(s);
    }

    int index(string s)
    {
        return st->get(s);
    }

    string name(int v)
    {
        return keys[v];
    }

    Graph * G()
    {
        return G;
    }
};
#endif
