#include <iostream>

using namespace std;

typedef struct node 
{
    node(int data):data(data), next(0){}
    ~node()
    {
        if (next) delete next;
    }

    int data;

    node* next;
} node;

// add 2 linked lists in reverse order. assume both list have equal amount of nodes represented
// as individual digits of the number in each list.

node* sum_of_list(node* l, node* r)  
{
    int sum = 0;
    int carry = 0;

    node* res = new node(0);
    node* tmp = res;

    while (l)
    {
        sum = carry + l->data + r->data;
        carry = (int) sum / 10;
        
        tmp->data = sum % 10;
        
        l = l->next;
        r = r->next;
        
        if (l)
            tmp = tmp->next = new node(0);
    } 

    return res;
}

int main() {

    node* h1 = new node(2);
    h1->next = new node(4);
    h1->next->next = new node(3);
    
    node* h2 = new node(5);
    h2->next = new node(6);
    h2->next->next = new node(4);

    node* result = sum_of_list(h1, h2);
    node* t = result;

    do {
        cout << t->data;
        t = t->next;

        if (t)
            cout  << " -> ";

    } while (t);

    cout << endl;
    
    delete result;
    delete h1;
    delete h2;

    return 0;
}
