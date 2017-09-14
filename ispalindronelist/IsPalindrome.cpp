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

bool isPalindrome(Node*& pn1, Node* pn2)
{
    if (!pn2) {
        return true;
    }
    
    if (!isPalindrome(pn1, pn2->next))
        return false;

    bool flag = (pn1->data == pn2->data);

    pn1 = pn1->next;

    return flag;
}

int  main() {

    LinkedList l1;

    l1.addNode(100);
    l1.addNode(200);
    l1.addNode(300);
    //l1.addNode(400);
    l1.addNode(300);
    l1.addNode(200);
    l1.addNode(100);

    print(l1);
    
    cout << endl;

    Node* pn = l1.head();

    bool stat = isPalindrome(pn, pn);
    
    if (stat) {
        cout << "List is a palindrome" << endl; 
    } else {
        cout << "List is not a palindrome" << endl;
    }

      return 0;
}
