#ifndef DEPTHFIRSTORDER_H
#define DEPTHFIRSTORDER_H

#include "C1/Unit3_Stacks/Queue.h"
#include "C1/Unit3_Stacks/Stack.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U2/Digraph.h"
#include <vector>
#include <iterator>

using namespace std;

class DepthFirstOrder {
    private:
        vector<bool> marked;
        Queue<int> * pre;
        Queue<int> * post;
        Stack<int> * reversePost;

        void dfs(Digraph * G, int v)
        {
            pre->enqueue(v);
            marked[v] = true;
            Bag<int>::Node * p = G->adj[v]->first;
            while(nullptr != p)
            {
                if(!marked[p->item])
                    dfs(G, p->item);
                p = p->next;
            }
            post->enqueue(v);
            reversePost->push(v);
            /* cout << v << endl; */
        }

    public:
        DepthFirstOrder(Digraph * G)
        {
            pre = new Queue<int>();
            post = new Queue<int>();
            reversePost = new Stack<int>();
            marked.reserve(G->getV());
            for(int i = 0; i < G->getV(); i++)
                marked[i] = false;
            for(int v = 0; v < G->getV(); v++)
                if(!marked[v])
                    dfs(G, v);
        }

        Queue<int> * getPre()
        {
            return pre;
        }

        Queue<int> * getPost()
        {
            return post;
        }

        Stack<int> * getReversePost()
        {
            return reversePost;
        }
};

#endif
