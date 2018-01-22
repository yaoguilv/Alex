template<class T>
class Bag {
private:
    class Node
    {
    public:
        T item;
        Node * next;
    };
    Node * first;
public:
    Bag();
    ~Bag();
    void add(T item);
    bool isEmpty();
};

template<class T>
Bag<T>::Bag()
{
    first = nullptr;
}

template<class T>
void Bag<T>::add(T item)
{
    Node * oldfirst = first;
    first = new Node();
    first->item = item;
    first->next = oldfirst;
}

template<class T>
bool Bag<T>::isEmpty()
{
    return nullptr == this->first;
}
