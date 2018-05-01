#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H

#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <iostream>
#include "C4/U3/Edge.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "util/CString.h"

using namespace std;

class EdgeWeightedGraph {
private:
    // number of vertices
    int V = 0;
    // number of edges
    int E = 0;
    // adjacency lists
    vector<Bag<Edge*>*> adj;

public:
    EdgeWeightedGraph(int V)
    {
        this->V = V;
        this->E = 0;
        adj.reserve(V);
        for(int i = 0; i < V; i++)
        {
            adj.push_back(new Bag<Edge*>());
        }
    }

    EdgeWeightedGraph(const string& fileName)
    {
        string sp = " ";
        ifstream inputFile;
        inputFile.open(fileName, fstream::in | fstream::out);
        vector<string> strArr;

        bool readCount = false;
        if(!inputFile.is_open())
            cout << "open file failed!" << endl;
        else
        {
            char buf[256];
            inputFile.getline(buf, 100);
            string strV = buf;
            inputFile.getline(buf, 100);
            string strECount = buf;
            V = stoi(strV);
            this->E = 0;
            adj.reserve(V);
            for(int i = 0; i < V; i++)
            {
                adj.push_back(new Bag<Edge*>());
            }

            int ECount = stoi(strECount);

            for(int i = 0; i < ECount; i++)
            {
                inputFile.getline(buf, 100);
                string strToSplit = buf;
                strArr.clear();
                CString::split(strToSplit, sp, strArr);
                int v = stoi(strArr[0]);
                int w = stoi(strArr[1]);
                double weight = stod(strArr[2]);
                Edge * e = new Edge(v, w, weight);
                addEdge(e);
            }
            inputFile.close();
        }
    }

    int getV()
    {
        return V;
    }

    int getE()
    {
        return E;
    }

    void addEdge(Edge* e)
    {
        int v = e->either();
        int w = e->other(v);
        adj[v]->add(e);
        adj[w]->add(e);
        E++;
    }

    void getAdj(int v, vector<Edge*>& arrVEdges)
    {
        Bag<Edge*>* myBag = adj[v];
        Bag<Edge*>::Node* pNode = myBag->first;
        while(nullptr != pNode)
        {
            Edge* pEdge = pNode->item;
            arrVEdges.push_back(pEdge);
            pNode = pNode->next;
        }
    }

    void getEdges(vector<Edge*>& arrEdges)
    {
        for(int v = 0; v < V; v++)
        {
            int selfLoops = 0;
            Bag<Edge*>* myBag = adj[v];
            Bag<Edge*>::Node* pNode = myBag->first;
            while(nullptr != pNode)
            {
                Edge* pEdge = pNode->item;
                if(pEdge->other(v) > v)
                    arrEdges.push_back(pEdge);
                pNode = pNode->next;
            }
        }
    }
};
#endif
