template<typename T>
class ResizingArrayStack
{
private:
    T * a;
    int N;
    int currentSize;

public:
    bool isEmpty();
    int size();
    void push(T item);
    T pop();
    ResizingArrayStack();
    ~ResizingArrayStack();
private:
    void resize(int max);
};

template<typename T>
ResizingArrayStack<T>::ResizingArrayStack()
{
    a = new int[1];
    N = 0;
    currentSize = 1;
}

template<typename T>
ResizingArrayStack<T>::~ResizingArrayStack()
{
    delete[] a;
}

template<typename T>
bool ResizingArrayStack<T>::isEmpty()
{
    return 0 == N;
}

template<typename T>
int ResizingArrayStack<T>::size()
{
    return N;
}

template<typename T>
void ResizingArrayStack<T>::resize(int max)
{
    T* temp = new T[max];
    for(int i = 0; i < N; i++)
    {
        temp[i] = a[i];
    }
    delete[] a;
    this->a = temp;
    this->currentSize = max;
}

template<typename T>
void ResizingArrayStack<T>::push(T item)
{
    // Add item to top of stack.
    if(N == this->currentSize) resize(2 * this->currentSize);
    this->a[N++] = item;
}

template<typename T>
T ResizingArrayStack<T>::pop()
{
    // Remove item from top of stack.
    T item = a[--N];
    a[N] = 0;
    if(N > 0 && N == this->currentSize/4) resize(this->currentSize/2);
    return item;
}
