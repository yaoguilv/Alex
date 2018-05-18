#ifndef EDGEWEIGHTEDDIGRAPH_H
#define EDGEWEIGHTEDDIGRAPH_H
#include "C4/U4/DirectedEdge.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "util/CString.h"

#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class EdgeWeightedDigraph {
private:
    // number of verteices
    int V;
    // number of edges
    int E;
    // adjacency lists
    Bag<DirectedEdge*>** adj;

public:
    EdgeWeightedDigraph(int inV)
    {
        this->V = inV;
        this->E = 0;
        adj = new Bag<DirectedEdge*>*[V];
        for(int v = 0; v < V; v++)
        {
            adj[v] = new Bag<DirectedEdge*>();
        }
    }

    EdgeWeightedDigraph(const string fileName)
    {
        ifstream inputFile;
        inputFile.open(fileName, fstream::in | fstream::out);
        vector<string> strArr;

        if(!inputFile.is_open())
        {
            cout << "open file failed!" << endl;
            return;
        }

        char buf[256];
        inputFile.getline(buf, 100);
        string strV = buf;
        inputFile.getline(buf, 100);
        string strECount = buf;
        this->V = stoi(strV);
        adj = new Bag<DirectedEdge*>*[V];
        for(int v = 0; v < V; v++)
        {
            adj[v] = new Bag<DirectedEdge*>();
        }
        this->E = 0;

        string sp = " ";
        for(int i = 0; i < stoi(strECount); i++)
        {
            inputFile.getline(buf, 100);
            string strToSplit = buf;
            strArr.clear();
            CString::split(strToSplit, sp, strArr);
            int v = stoi(strArr[0]);
            int w = stoi(strArr[1]);
            double weight = stod(strArr[2]);
            DirectedEdge* e = new DirectedEdge(v, w, weight);
            addEdge(e);
        }
        inputFile.close();
    }

    int getV()
    {
        return this->V;
    }

    int getE()
    {
        return this->E;
    }

    void addEdge(DirectedEdge* e)
    {
        adj[e->from()]->add(e);
        this->E++;
    }

    void getAdj(int v, Bag<DirectedEdge*>& edgeBag)
    {
        Bag<DirectedEdge*>::Node* myB = adj[v]->first;
        while(nullptr != myB)
        {
            edgeBag.add(myB->item);
            myB = myB->next;
        }
    }

    void getEdges(vector<DirectedEdge*>& edges)
    {
        for(int v = 0; v < V; v++)
        {
            Bag<DirectedEdge*>::Node* myB = adj[v]->first;
            while(nullptr != myB)
            {
                edges.push_back(myB->item);
                myB = myB->next;
            }
        }
    }
};

#endif
