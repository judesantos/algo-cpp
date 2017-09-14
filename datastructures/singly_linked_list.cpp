#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct node {
        node():next(0) {}
        ~node(){}

        node* next;
        T data;
};

template <typename T>
class singly_linked_list 
{
    public:
        singly_linked_list();
        virtual ~singly_linked_list();

        int push(T data, unsigned int idx = 0); // default inserts to head of list
        T pop(unsigned int idx = 0);            // default delete head  of list

        void empty(); // delete all
        unsigned int size() { return this->last_index + 1; }

    private:
        struct node<T>* head;
        int last_index;
};

template <typename T>
singly_linked_list<T>::singly_linked_list():
    last_index(0),
    head(0)
{
}

template <typename T>
singly_linked_list<T>::~singly_linked_list()
{
    this->empty(); 
}

template <typename T>
int singly_linked_list<T>::push(T data, unsigned int idx) 
{
    if (idx > last_index) {
        return -1;
    }
    
    if (!this->head)
    {
        this->head = new node<T>();
        this->head->data = data;

        return 0;
    } 
    else 
    {
        struct node<T>* prev = this->head;
        struct node<T>* next = this->head;

        int x = 0;

        while (idx != x++) {
            prev = next;
            next = prev->next;
        }
       
        struct node<T>* _new = new node<T>();
        _new->data = data;
        _new->next = next;

        if (idx == 0) {
            this->head  = _new;
        } else {
            prev->next = _new;
        }

        ++this->last_index;
    }
    
    return idx; 
}

template <typename T>
T singly_linked_list<T>::pop(unsigned int idx)
{
    if (idx > last_index) {
        return 0;
    }
    
    struct node<T>* prev = this->head;
    struct node<T>* next = this->head;

    int x = 0;

    do {
        prev = next;
        next = prev->next;
    } 
    while (idx != x++);
    
    if (idx == 0)
    {
        this->head = next;
    } else {
        prev->next = next;
    }

    --this->last_index;

    T t = prev->data;
    delete prev;
    
    return t; 
}

template <typename T>
void singly_linked_list<T>::empty() 
{
    while(0 <= this->last_index) {
        this->pop(this->last_index--);
    }
}

int main() {

    singly_linked_list<string> ll;

    ll.push("String");
    ll.push("a");
    ll.push("is");
    ll.push("this");

    ll.push("fucking", 3);
    
    cout << ll.size() << endl;

    cout << ll.pop(4) << endl;
    
    cout << ll.size() << endl;

    cout << ll.pop(3) << endl;
    
    cout << ll.size() << endl;

    cout << ll.pop(2) << endl;
    
    cout << ll.size() << endl;

    cout << ll.pop(1) << endl;
    
    cout << ll.size() << endl;

    cout << ll.pop(0) << endl;

    cout << ll.size() << endl;

}
