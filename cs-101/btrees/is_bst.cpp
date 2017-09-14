#include <iostream>
#include <queue>

using namespace std;

class node {
    public:
        node(int data):data(data),left(0),right(0){}
        ~node() {
            if (left) delete left;
            if (right) delete right;
        }

        int data;

        node* left;
        node* right;
};

/**
 * is_bst - determine if the btree is a bst.
 *          traversal algo is bfs.
 *
 *          complexity is O(N)
 */
bool is_bst(node* root) {

    if (!root)
        return true;

    queue<node*>* p = new queue<node*>();
    p->push(root);
    bool a_bst = true;

    // iterate at tree level
    while(p->size()) {
        // set parent as current level.
        // iterate to all nodes in current level
        // then check each edge to be left <= node < right (a bst).
        queue<node*>* c = p;
        p = new queue<node*>();
        // iterate through all nodes in this level
        // algo. doesnt have to reach the bottom of the tree if not a bst.
        while (c->size()) {
            node* n = c->front();
            c->pop();
            
            cout << n->data << " ";

            if (n->left) {
                if (n->left->data <= n->data)
                    p->push(n->left);
                else {
                    a_bst = false;
                    break;
                }
            }

            if (n->right) {
                if (n->right->data > n->data)
                    p->push(n->right);
                else {
                    a_bst = false;
                    break;
                }
            }
        }

        delete c;

        if (!a_bst)
            break;
        
        cout << endl;
    }
    delete p;

    return a_bst;
}

int main() {

    node* head = new node(5);

    head->left = new node(3);
    head->right = new node(7);

    head->left->left = new node(2);
    head->left->right = new node(4);
    head->left->left->left = new node(1);

    head->right->left = new node(6);
    head->right->right = new node(9);
    head->right->right->left = new node(8);
    head->right->right->right = new node(10);
   
    cout << "is bst: " << (is_bst(head) ? "yes" : "no") << endl;

    delete head;

    return 0;
}
