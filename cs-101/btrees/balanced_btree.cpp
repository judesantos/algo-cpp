#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class node {
    public:
        node(int data):data(data), left(0), right(0) {}
        ~node() {
            if (left) delete left;
            if (right) delete right;
        }

        int data;

        node* left;
        node* right;
};

int get_height(node* n) {

    if (!n) 
        return 0;

    int lh = get_height(n->left);
    if (lh == -1)
        return lh;

    int rh = get_height(n->right);
    if (rh == -1) 
        return rh;

    if (abs(lh-rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

bool is_balanced(node* root) {
    return get_height(root) != -1;
}

int main() {

    node* head = new node(1);

    head->left = new node(2);
    head->right = new node(3);
    
    head->left->left = new node(4);
   // head->left->right = new node(5);

   // head->left->left->left = new node(6);
   // head->left->left->right = new node(7);

    string balanced = is_balanced(head) ? "Yes" : "No";

    cout << "is balanced: " << balanced << endl;

    delete head;
    
    return 0;
}
