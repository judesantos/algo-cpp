#include <iostream>

//#include "hello.h"
#include "LinkedList.h"

using namespace std;

int main() {
    /*
    Hello *h = new Hello("Welcome to CPP!!"); 

    cout << h->sayHello() << endl;

    delete h;
    */

    LinkedList l;

    l.addNode(1);
    l.addNode(2);
    l.addNode(3);
    l.addNode(4);

    cout << "|||||||| Normal |||||||||" << endl;

    Node* pN = l.getList();

    while (pN != 0) {
    
        cout << pN->data << endl;
        pN = pN->next;
    }

    cout << "|||||||| Reversed |||||||||" << endl;
 
    l.reverse();

    pN = l.getList();

    while (pN != 0) {
    
        cout << pN->data << endl;
        pN = pN->next;
    }

    return 0;
}
