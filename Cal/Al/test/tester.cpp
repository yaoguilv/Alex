#include <iostream>
#include <string>
#include "C2/U1/MyDate.h"
#include "C3/U2/BST.h"

using namespace std;

int main(int argc, char ** argv)
{
    BST<MyDate *, string> * myBST = new BST<MyDate *, string>();

    cout << "now size:" << endl;
    cout << myBST->size();

    MyDate ** dat = new MyDate*[3];
    dat[0] = new MyDate(1, 1, 2015);
    dat[1] = new MyDate(1, 1, 2010);
    dat[2] = new MyDate(1, 1, 2017);

    myBST->put(dat[0], "bbb");
    myBST->put(dat[1], "aaa");
    myBST->put(dat[2], "ccc");

    cout << "now size: " << endl;
    cout << myBST->size();

    cout << "key 2010's value is:" << endl;
    cout << myBST->get(dat[1]) << endl;

    cout << "min key:" << endl;
    cout << myBST->min()->toString() << endl;

    cout << "floor of 2015 is:" << endl;
    cout << myBST->floor(dat[0])->toString();

    cout << "select 2015 :" << endl;
    cout << myBST->select(2)->toString() << endl;

    cout << "rank of 2017 is :" << endl;
    cout << myBST->rank(dat[2]) << endl;

    cout << "print all Node" << endl;
    myBST->print();

    cout << "now delete min: " << endl;
    myBST->deleteMin();
    myBST->print();

    cout << "now delete 2015:" << endl;
    myBST->deleteKey(dat[0]);
    myBST->print();

    /* Iterable<Integer> myIterable = myBST.keys(); */
    /* Iterator<Integer> myIt = myIterable.iterator(); */
    /* System.out.println("now Iterable the tree："); */
    /* while(myIt.hasNext()) */
    /* { */
    /*     System.out.println(myIt.next()); */
    /* } */
}

