#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "C1/Unit3_Stacks/Bag.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

class Digraph {
    private:
        int V;
        int E;
    public:
        Bag<int> ** adj;

        Digraph(const string& fileName)
        {
            string sp = " ";
            vector<int> * myArr = new vector<int>();
            ifstream inputFile;
            inputFile.open(fileName, fstream::in | fstream::out);
            if(inputFile.is_open())
                cout << "open file failed!" << endl;
            else
            {
                char buf[256];
                while(!inputFile.eof())
                {
                    inputFile.getline(buf, 100);
                    string strToSplit = buf;
                    int separateIndex = strToSplit.find(sp);
                    if(string::npos != separateIndex)
                    {
                        string strOne = strToSplit.substr(0, separateIndex);
                        string strTwo = strToSplit.substr(separateIndex + 1);
                        int iOne = stoi(strOne);
                        int iTwo = stoi(strTwo);
                        if(myArr->end() == find(myArr->begin(), myArr->end(), iOne))
                            myArr->push_back(iOne);
                        if(myArr->end() == find(myArr->begin(), myArr->end(), iTwo))
                            myArr->push_back(iTwo);
                    }
                }
                inputFile.close();
            }
            this->V = myArr->size();
            this->E = 0;
            adj = new Bag<int>*[this->V];
            for(int i = 0; i < this->V; i++)
                adj[i] = new Bag<int>();
            inputFile.open(fileName, fstream::in | fstream::out);
            if(inputFile.is_open())
                cout << "open file failed!" << endl;
            else
            {
                char buf[256];
                while(!inputFile.eof())
                {
                    inputFile.getline(buf, 100);
                    string strToSplit = buf;
                    int separateIndex = strToSplit.find(sp);
                    if(string::npos != separateIndex)
                    {
                        string strOne = strToSplit.substr(0, separateIndex);
                        string strTwo = strToSplit.substr(separateIndex + 1);
                        int iOne = stoi(strOne);
                        int iTwo = stoi(strTwo);
                        addEdge(iOne, iTwo);
                    }
                }
                inputFile.close();
            }
        }

        Digraph(int v)
        {
            this->V = v;
            this->E = 0;
            adj = new Bag<int>*[this->V];
            for(int i = 0; i < this->V; i++)
                adj[i] = new Bag<int>();
        }

        int getV()
        {
            return this->V;
        }

        int getE()
        {
            return this->E;
        }

        void addEdge(int v, int w)
        {
            adj[v]->add(w);
        }

        Digraph * reverse()
        {
            Digraph * R = new Digraph(this->V);
            for(int i = 0; i < this->V; i++)
            {
                Bag<int>::Node * p = adj[i]->first;
                while(nullptr != p)
                {
                    R->addEdge(p->item, i);
                    p = p->next;
                }
            }
            return R;
        }
};
#endif
