#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


struct Node {
    int data;
    Node* next;
};

class LinkedList {

    public: 
        LinkedList();
        ~LinkedList();

        void addNode(int value);
        void prepend(int value);
        void reverse();

        Node* head();
        int size();

        Node* getList();

    private:
        Node* pHead;

        void clear();
};

#endif // __LINKED_LIST_H__
