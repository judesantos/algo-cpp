#include <iostream>

using namespace std;

template <typename T>
struct node {
    node(T data):data(data),next(0){}
    ~node() {
        cout << "deleting " << data << endl; 
    }

    node<T>* next;
    T data;

    void addNode(T data) 
    {
        node<T>* curr = this;
        
        while(curr->next) {
            curr = curr->next;
        }
    
        curr->next = new node(data);
    }
};

template <typename T>
bool removeNode(node<T>* head, int data) {

    node<T>* tmp = 0;

    if (head->data == data) {
        tmp = head;
        head = head->next;
    }
    else 
    {
        node<T>* curr = head->next;
        node<T>* prev = head;

        while (curr) {

            if (curr->data == data) {
                tmp = curr;
                prev->next = curr->next;
                break;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
   
    if (tmp) {
        delete tmp;
        return true;
    }

    return false;
}

bool removeDuplicates(node<int>* head, int data) {
    
    if (!head)
        return false;

    node<int>* tmp = 0;
    node<int>* ref = head;
    bool found = false;

    // find first node with same value as input data
    // make then as reference - do not remove, but remove duplicates 
    while (ref) {
        if (ref->data == data) {
            ref = ref->next;
            break;
        }
        ref = ref->next;
    }

    while (ref) {
        if (ref->data == data) {
            tmp = ref->next;
            delete ref;
            ref = tmp;
            found = true;
        }
        else
        {
            ref = ref->next;
        }
    }

    return found;
}

bool removeDuplicates(node<int>* head) {
    
    if (!head)
        return false;
    
    node<int>* curr = head;
    bool found = false;

    while (curr) {
        found = removeDuplicates(curr, curr->data);
        curr = curr->next;
    }

    return found;
}

int main() {

    node<int>* head = new node<int>(1);
    head->addNode(2);

    cout << "removenode 2" << endl;

    removeNode<int>(head, 2);

    node<int>* t = head;
    
    while (t) {
        cout << t->data << endl;
        t = t->next;
    }

    cout << "add nodes" << endl;

    head->addNode(2);
    head->addNode(3);
    head->addNode(2);

    t = head;
    
    while (t) {
        cout << t->data << endl;
        t = t->next;
    }
   
    cout << "removedups 2" << endl;
    
    removeDuplicates(head);

    t = head;

    while(t) 
    {
        node<int>* tmp = t->next;
        delete t;
        t = tmp;
    }

    return 0;
}
