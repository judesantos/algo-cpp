#include <iostream>

using namespace std;

typedef struct node {
    node(int data):data(data), left(0), right(0){}
    ~node() {
        if (left) delete left;
        if (right) delete right;
    }

    int data;
    node* left;
    node* right;

} node;

void pre_order_dfs(node* head) {
    if (!head)
        return;

    cout << head->data << " ";
    pre_order_dfs(head->left);
    pre_order_dfs(head->right);
}


void post_order_dfs(node* head) {
    if (!head)
        return;

    post_order_dfs(head->left);
    post_order_dfs(head->right);
    cout << head->data << " ";
}

void in_order_dfs(node* head) {
    if (!head)
        return;

    in_order_dfs(head->left);
    cout << head->data << " ";
    in_order_dfs(head->right);
}

int main() {
    
    node* head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->right->left = new node(6);
    head->right->right = new node(7);
    head->left->left = new node(4);
    head->left->right = new node(5);

    pre_order_dfs(head);
    cout << endl;
    in_order_dfs(head);
    cout << endl;
    post_order_dfs(head);
    cout << endl;
    
    delete head;

    return 0;
}
