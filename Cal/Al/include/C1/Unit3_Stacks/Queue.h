#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <class T>
class Queue {
private:
    int N;
    class Node
    {
    public:
        T item;
        Node *next;
    };
    Node * first;
    Node * last;

public:
    Queue();
    ~Queue(){};
    bool isEmpty();
    int size();
    void enqueue(T item);
    T dequeue();
};

template <class T>
Queue<T>::Queue()
{
    first = NULL;
    last = NULL;
    N = 0;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return 0 == N;
}

template <class T>
int Queue<T>::size()
{
    return N;
}

template <class T>
void Queue<T>::enqueue(T item)
{
    Node * x = new Node();
    x->item = item;
    if(isEmpty())
    {
        first = x;
        last = x;
    }
    else
    {
        last->next = x;
        last = x;
    }
    N++;
}

template <class T>
T Queue<T>::dequeue()
{
    T item = first->item;
    first = first->next;
    N--;
    if(isEmpty())
        last = NULL;
    return item;
}

#endif
