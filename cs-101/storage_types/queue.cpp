#include <iostream>
#include <exception>

using namespace std;

template <typename T>
struct node {
    node(int data):data(data), next(0){}
    ~node() {
        cout << "deleting " << data << endl;
    }

    node<T>* next;

    T data;
};

template <typename T>
struct queue {
    queue():first(0), last(0){}
    ~queue() {
        clear();
    }

    node<T>* first;
    node<T>* last;

    void add(T data) {
        node<T>* n = new node<T>(data);
        if (last)
            last->next = n;

        last = n;

        if (!first)
            first = last;
    }

    T remove() {
        if (!first)
            throw ios_base::failure("Queue is empty");

        node<T>* t = first;
        first = first->next;

        T data = 0;
        
        data = t->data;
        delete t;

        if (!first)
            last = first;

        return data;
    }

    T peek() {
        if (!first)
            throw ios_base::failure("Queue is empty");

        return first;
    }

    bool isEmpty() {
        return !first;
    }

    void clear() {
        node<T>* t = first;

        while(t) {
            first = t->next;
            delete t;
            t = first;
        }
    }
};

int main() {

    queue<int> q;

    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    
    cout << q.remove() << endl;
    cout << q.remove() << endl;
    cout << q.remove() << endl;
    cout << q.remove() << endl;

    return 0;
}
