#include <iostream>

using namespace std;

template <typename T>
class node 
{
    public:
        node():next(0), prev(0) {}
        virtual ~node(){}

        T t;
       node<T>* next;
        node<T>* prev;
};

template <typename T>
class dequeue
{
    public:
        dequeue();
        ~dequeue();

        T popFront();
        T popBack();

        int pushFront();
        int pushBack();

        unsigned int size() { return count; }

    private:
        node<T>* head;
        node<T>* tail;
        int count;
};

template <typename T>
dequeue<T>::dequeue():
    count(0),
    tail(0),
    head(0)
{
}

template <typename T>
dequeue<T>::~dequeue()
{
}

template <typename T>
T dequeue<T>::popFront()
{
}

template <typename T>
T dequeue<T>::popBack()
{
}

template <typename T>
int dequeue<T>::pushFront()
{
}

template <typename T>
int dequeue<T>::pushBack()
{
}

