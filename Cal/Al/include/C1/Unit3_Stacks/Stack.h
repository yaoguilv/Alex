template <class T>
class Stack
{
private:
    int N;
    class Node
    {
    public:
        T item;
        Node * next;
    };
    Node * first;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    int size();
    void push(T item);
    T pop();
};

template<class T>
Stack<T>::Stack()
{
    N = 0;
    first = NULL;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return 0 == N;
}

template<class T>
int Stack<T>::size()
{
    return N;
}

template<class T>
void Stack<T>::push(T item)
{
    // Add item to top of stack.
    Node * oldfirst = first;
    first = new Node();
    first->item = item;
    first->next = oldfirst;
    N++;
}

template<class T>
T Stack<T>::pop()
{
    // Remove item from top of stack.
    T item = first->item;
    first = first->next;
    N--;
    return item;
}
