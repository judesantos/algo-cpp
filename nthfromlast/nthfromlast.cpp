#include <iostream>
#include "../inc/LinkedList.h"

using namespace std;

void print(LinkedList& l)
{
    Node* pN = l.getList();
    
    cout << endl;

    while (pN != 0) {
    
        cout << pN->data << " ";
        pN = pN->next;
    }

}

int nthFromLast(LinkedList* pl, int n) {

    int size = pl->size();
    int steps = size - n;
    
    Node* pn = pl->head();

    while (0 < steps--) {
        pn = pn->next;
    }

    return pn->data;
}

int  main() {

    LinkedList l1;

    l1.addNode(100);
    l1.addNode(200);
    l1.addNode(300);
    l1.addNode(400);
    l1.addNode(300);
    l1.addNode(200);
    l1.addNode(600);
    l1.addNode(700);
    l1.addNode(800);
    l1.addNode(900);
    l1.addNode(1000);

    print(l1);

    cout << "value at 4 from last " << endl;

    cout << nthFromLast(&l1, 4) << endl;

    cout << endl;

    return 0;
}
