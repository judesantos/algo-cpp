#include "../inc/LinkedList.h"

LinkedList::LinkedList() {
    this->pHead = 0;
}

LinkedList::~LinkedList() {
    // destroy list
    this->clear();
}

void LinkedList::addNode(int value)
{
    Node* pn = new Node();
    pn->next = 0;
    pn->data = value;

    if (this->pHead == 0) {
        this->pHead = pn;
    } else {
        Node* ph = this->pHead;

        while (ph->next != 0) {
            ph = ph->next;
        }

        ph->next = pn;
    }
}

void LinkedList::clear()
{
    Node* pNext = this->pHead;
    Node* pCurr = 0;

    while (pNext != 0)
    {
        pCurr = pNext;
        pNext = pCurr->next;
        
        delete pCurr;
        pCurr = 0;
    } 
}

void LinkedList::prepend(int value) 
{
    Node* pn = new Node();
    pn->data = value;
    pn->next = 0;

    Node* pPrev = this->pHead;
    this->pHead = pn;
    this->pHead->next = pPrev;
}

int LinkedList::size() 
{
    int count = 0;
    Node* pCurr = this->pHead;
    
    while(pCurr) 
    {
        count++;
        pCurr = pCurr->next;
    }

    return count;
}

void LinkedList::reverse()
{
    Node* pCurr = this->pHead;
    Node* pNext = 0;
    Node* pNextNext = 0;

    while (pCurr != 0) 
    {
        this->pHead = pCurr;
    
        pNext = pCurr->next;
        pCurr->next = pNextNext;
        pNextNext = pCurr;
        pCurr = pNext;
    } 
}

Node* LinkedList::head() 
{
    return this->pHead;
}

Node* LinkedList::getList() 
{
    return this->pHead;   
}
