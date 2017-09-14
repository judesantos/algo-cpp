#include <iostream>
#include "../inc/LinkedList.h"

using namespace std;

void  reverse_linkedlist(Node* pn) {

    if (pn->next) {
        reverse_linkedlist(pn->next);
    }

    cout << pn->data << " " << endl;
}

int main() {

    LinkedList ll;

    ll.addNode(100);
    ll.addNode(200);
    ll.addNode(300);
    ll.addNode(400);
    ll.addNode(300);
    ll.addNode(200);
    ll.addNode(600);
    ll.addNode(700);
    ll.addNode(800);
    ll.addNode(900);
    ll.addNode(1000);

    Node* pn = ll.getList();

    reverse_linkedlist(pn);

    return 0;
}

