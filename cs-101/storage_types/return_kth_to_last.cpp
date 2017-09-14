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

void callback(int idx, int k, int val) {
    if (idx == k)
        cout << "found kth index: " << idx << ", val: " << val << endl;
}

int kthToLast(node<int>* node, int k, void (*func)(int, int, int)) {

    if (!node)
        return 0;
    
    int index = kthToLast(node->next, k, func) + 1;
    
    func(index, k, node->data);

    return index;
}

node<int>* iterativeNthToLast(node<int>* head, int k) {

    if (!head)
        return 0;

    node<int>* pk = head;
    node<int>* pc = head;

    for (int i = 0; i < k; i++) {
        if (!pc)
            return 0;
        pc = pc->next;
    }

    while(pc) {
        pk = pk->next;
        pc = pc->next;
    }

    return pk;
}

int main() {

    node<int>* head = new node<int>(1);
    head->addNode(2);
    head->addNode(3);
    head->addNode(410);
    head->addNode(5);
    head->addNode(6);

    kthToLast(head, 3, callback);

    node<int>* k = iterativeNthToLast(head, 3);

    cout << " using iterative approach - val: " << k->data << endl;

    node<int>* t = head;
    
    while(t) 
    {
        node<int>* tmp = t->next;
        delete t;
        t = tmp;
    }

    return 0;
}

