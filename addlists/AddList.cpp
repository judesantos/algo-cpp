#include <iostream>
#include "../inc/LinkedList.h"

using namespace std;

int doAddList(Node* pn1, Node* pn2, LinkedList* pl3) 
{
    if (pn1 == 0)
        return 0;

    int carry = doAddList(pn1->next, pn2->next, pl3);
    
    int sum = carry + pn1->data + pn2->data;
    int carryOver = sum / 10;
    int nval = sum % 10;

    pl3->prepend(nval);

    return carryOver;
}



void addList(LinkedList* pl1, LinkedList* pl2, LinkedList* pl3) 
{ 
    int carry = doAddList(pl1->head(), pl2->head(), pl3);
    if (carry) 
    {
       pl3->prepend(carry); 
    }
}

void prependList(LinkedList* pl1, LinkedList* pl2)
{
    int szl1 = pl1->size();
    int szl2 = pl2->size();

    int diff = szl1 > szl2 ? szl1 - szl2 : szl2 - szl1;
    LinkedList* pl = szl1 > szl2 ? pl2 : pl1; 

    while (0 < diff--) {
        pl->prepend(0);
    } 
}

void print(LinkedList& l)
{
    Node* pN = l.getList();
    
    cout << endl;

    while (pN != 0) {
    
        cout << pN->data << " ";
        pN = pN->next;
    }

}

int main() {

    LinkedList l1;

    l1.addNode(1);
    l1.addNode(2);
    l1.addNode(3);
    l1.addNode(4);
    l1.addNode(5);
    l1.addNode(6);
    l1.addNode(7);

    LinkedList l2;

    l2.addNode(9);
    l2.addNode(9);
    l2.addNode(9);
    l2.addNode(9);
    l2.addNode(9);

    cout << "Pre prepend";

    print(l1);
    print(l2);

    cout << endl;
   
    prependList(&l1, &l2);
   
    cout << "Post prepend";

    print(l1);
    print(l2);

    cout << endl;

    LinkedList l3;

    addList(&l1, &l2, &l3);

    
    cout << "Post sum list";

    print(l3);

    return 0;
}
