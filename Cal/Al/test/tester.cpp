#include <iostream>
#include <string>
#include "C2/U1/MyDate.h"
#include "C3/U3/RedBlackBST.h"

using namespace std;

int main(int argc, char ** argv)
{
    public static void main(String[] args)
    {
        RedBlackBST<MyDate *, string> * myRB = new RedBlackBST<MyDate *, string>();

        cout << "now size:" << endl;
        cout << myRB->size();

        MyDate ** dat = new MyDate*[3];
        dat[0] = new MyDate(1, 1, 2015);
        dat[1] = new MyDate(1, 1, 2010);
        dat[2] = new MyDate(1, 1, 2017);

        myRB->put(dat[0], "bbb");
        myRB->put(dat[1], "aaa");
        myRB->put(dat[2], "ccc");

        cout << "now size: " << endl;
        cout << myRB->size();

        cout << "key 2010's value is:" << endl;
        cout << myBST->get(dat[1]) << endl;
        cout << "key 2015's value is:" << endl;
        cout << myBST->get(dat[0]) << endl;
        cout << "key 2017's value is:" << endl;
        cout << myBST->get(dat[2]) << endl;
    }

}
