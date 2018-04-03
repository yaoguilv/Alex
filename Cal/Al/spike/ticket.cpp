#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void myFun(vector<int> m)
{
    m.push_back(2);
    m.push_back(4);
}

int main()
{
    vector<int> n;
    myFun(n);
    for(vector<int>::iterator it = n.begin(); it != n.end(); it++)
        cout << *it << endl;
    return 0;
}

/* #include <iostream> */


/* using namespace std; */

/* class A */
/* { */
/* private: */
/*     int m; */
/* public: */
/*     void setM(int m) */
/*     { */
/*         this->m = m; */
/*     } */
/*     int getM() */
/*     { */
/*         return this->m; */
/*     } */
/* }; */
/* class B */
/* { */
/* private: */
/*     int n; */
/* public: */
/*     void setN(int n) */
/*     { */
/*         this->n = n; */
/*     } */
/*     int getN() */
/*     { */
/*         return this->n; */
/*     } */
/* }; */

/* class C { */
/* private: */
/*     class Node */
/*     { */
/*         // linked-list node */
/*     public: */
/*         A * key; */
/*         B * value; */
/*         Node * next; */
/*         Node(A * key, B * value, Node * next) */
/*         { */
/*             this->key = key; */
/*             this->value = value; */
/*             this->next = next; */
/*         } */
/*     }; */
/*     Node * first = nullptr; */

/* public: */
/*     void initKeys() */
/*     { */
/*         Node * tmpP; */
/*         for(int i = 0; i < 3; i++) */
/*         { */
/*             A * pA = new A(); */
/*             pA->setM(i + 1); */
/*             B * pB = new B(); */
/*             pB->setN(10 * (i + 1)); */


/*             if(nullptr == first) */
/*             { */
/*                 first =new Node(pA, pB, nullptr); */
/*             } */
/*             else */
/*             { */
/*                 tmpP = first; */
/*                 while(nullptr != tmpP->next) */
/*                 { */
/*                     tmpP = tmpP->next; */
/*                 } */
/*                 tmpP->next = new Node(pA, pB, nullptr); */
/*             } */
/*         } */
/*     } */

/*     A ** getKeys() */
/*     { */
/*         initKeys(); */
/*         int arrSize = 3; */
/*         A * keyArr[arrSize]; */
/*         A ** returnKey = keyArr; */
/*         int n = 0; */
/*         for(Node * x = first; x != nullptr; x = x->next) */
/*         { */
/*             keyArr[n] = x->key; */
/*             n++; */
/*         } */

/*         for(int i = 0; i < arrSize; i++) */
/*         { */
/*             cout << keyArr[i] << "  " << keyArr[i]->getM() << "   "; */
/*             cout << returnKey[i] << endl; */
/*         } */
/*         return keyArr; */
/*     } */
/* }; */

/* // execute command: bin/ticket dd */
/* int main(int argc, char ** argv) */
/* { */

/*     C * myC = new C(); */
/*     myC->initKeys(); */
/*     A ** myA = myC->getKeys(); */
/*     for(int i = 0; i < 3; i++) */
/*     { */
/*         cout << myA[i] << "  " << endl; */
/*     } */

/*     return 0; */
/* } */
