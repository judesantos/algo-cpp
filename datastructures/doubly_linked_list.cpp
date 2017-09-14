#include <iostream>

using namespace std;

template <typename T>
class node 
{
    public:
        node():next(0), prev(0) {}
        virtual ~node(){}

        T data;
        node<T>* next;
        node<T>* prev;
};

template <typename T>
class doubly_linked_list
{
    public:
        doubly_linked_list();
        ~doubly_linked_list();

        T pop();
        T popBack();

        T front();
        T back();

        int push(T t);
        int pushBack(T t);

        unsigned int size() { return count; }

    private:
        node<T>* head;
        node<T>* tail;
        int count;
};

template <typename T>
doubly_linked_list<T>::doubly_linked_list():
    count(0),
    tail(0),
    head(0)
{
}

template <typename T>
doubly_linked_list<T>::~doubly_linked_list()
{
    while(0 <= this->count) {
        this->pop();
    }
}

template <typename T>
T doubly_linked_list<T>::pop()
{
    if (!this->size()) 
    {
        return 0;
    }

    T t = this->head->data;

    node<T>* n = this->head;

    if (this->head->next != 0)
    {
       this->head = this->head->next;
       this->head->prev = 0;
    }
    else 
    {
        this->head = 0;
    }

    count--;
    delete n;

    return t;
}

template <typename T>
T doubly_linked_list<T>::popBack()
{
    if (!this->size()) 
    {
        return 0;
    }

    T t = this->tail->data;

    node<T>* n = this->tail;

    if (this->tail->next != 0)
    {
       this->tail = this->tail->prev;
       this->tail->prev = 0;
    }
    else 
    {
        this->head = 0;
    }

    this->count--;
    delete n;

    return t;
}

template <typename T>
int doubly_linked_list<T>::push(T t)
{
    node<T>* n = new node<T>();
    n->data = t;

    if (!this->size()) 
    {
        this->head = this->tail = n;
    }
    else 
    {
        n->next = this->head;
        this->head->prev = n;
        this->head = n;
    }
    
    this->count++;

    return count;
}

template <typename T>
int doubly_linked_list<T>::pushBack(T t)
{
    node<T>* n = new node<T>();
    n->data = t;

    if (!this->size()) 
    {
        this->head = this->tail = n;
    }
    else 
    {
        this->tail->next = n;
        n->prev = this->tail;
        this->tail = n;
    }

    this->count++;

    return count;
}

template <typename T>
T doubly_linked_list<T>::front()
{
    if (!this->size())
    {
        return 0;
    }

    return this->head->data;
}


template <typename T>
T doubly_linked_list<T>::back()
{
    if (!this->size())
    {
        return 0;
    }

    return this->tail->data;
}


int main()
{
    doubly_linked_list<string> dll;

    dll.push("is");
    dll.pushBack("a");
    dll.push("this");
    dll.pushBack("string");

    cout << dll.size() << endl;
    
    cout << "front: " << dll.front() << endl;
    cout << "back: " << dll.back() << endl;

    cout << dll.pop() << endl;
    cout << dll.pop() << endl;
    cout << dll.pop() << endl;
    cout << dll.pop() << endl;
    
    cout << dll.size() << endl;
}

