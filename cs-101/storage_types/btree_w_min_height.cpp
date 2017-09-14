#include <iostream>
#include <list>
#include <vector>
#include <math.h>

using namespace std;

class node {
    public:
        node(int data):data(data), left(0), right(0){}
        ~node() {
            cout << data << " ";
            if(left) delete left;
            if(right) delete right;
        }

        int data;

        node* left;
        node* right;
};

node* make_min_tree(int* arr, int start, int end) {
    
    if (end < start)
        return 0;

    int mid = (start + end) / 2;
    
    node* n = new node(arr[mid]);

    n->left = make_min_tree(arr, start, mid - 1);
    n->right = make_min_tree(arr, mid + 1, end);
    
    return n;
}

void parse_tree(node* head) {

    if (!head)
        return;

    cout << head->data << " ";

    parse_tree(head->left);

    parse_tree(head->right);
}

vector<list<node*>* >* parse_tree_bfs(node* head) {

    list<node*>* q = new list<node*>();

    q->push_back(head);

    vector<list<node*>* >* levels = new vector<list<node*>* >();
    int level = 0;

    while(q->size()) {

        levels->push_back(q);
        list<node*>* parents = q;
            
        list<node*>::iterator it = parents->begin();

        q = new list<node*>();
        
        for (;it != parents->end(); ++it) {

            node* n = *it;

            if (n->left) {
                q->push_back(n->left);
            }

            if (n->right) {
                q->push_back(n->right);
            }
        }
    }

    return levels;
}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int len = sizeof(arr) / sizeof(arr[0]);

    node* head = make_min_tree(arr, 0, len-1);

    cout << "parse tree: " << endl;

    parse_tree(head);
    cout << endl;

    cout << "parse tree bfs: " << endl;

    vector<list<node*>* >* levels = parse_tree_bfs(head);
    vector<list<node*>* >::iterator it = levels->begin();

    for (;it != levels->end(); ++it) {
        list<node*>* nodes = *it;
        list<node*>::iterator lit = nodes->begin();
        for (;lit != nodes->end(); ++lit) {
            cout << (*lit)->data << " ";
        }
        cout << endl;
        delete nodes;
    }
    delete levels;

    cout << endl;

    cout << "Deleting tree: " << endl;

    if (head)
        delete head;
    cout << endl;

    return 0;
}
