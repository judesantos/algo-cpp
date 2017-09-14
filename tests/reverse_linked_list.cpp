#include <iostream>

using namespace std;

class node 
{
    public:
        node():next(0), data(-1){}
        node* next;
        int data;
};

class linked_list
{
    public:
        linked_list(): head(0) {}
        ~linked_list(){}

        void add(int t);
        void reverse();
        void print();

    private:
        node* head;
};

void linked_list::add(int t)
{
    node* n = new node();
    n->data = t;

    if (!this->head) {
        this->head = n;
    }
    else 
    {
        node* tmp = this->head;

        while(tmp->next)
            tmp = tmp->next;

        tmp->next = n;
    }
}

void linked_list::reverse()
{
    node* n1 = this->head;
    node* n2 = 0;
    node* n3 = 0;

    while (n1) {
        this->head = n1;
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
}

void linked_list::print()
{
    node* tmp = this->head;

    while(tmp)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

int main() 
{
    linked_list ll;
    
    ll.add(5);
    ll.add(4);
    ll.add(3);
    ll.add(2);
    ll.add(1);

    ll.print();

    ll.reverse();

    ll.print();
}
