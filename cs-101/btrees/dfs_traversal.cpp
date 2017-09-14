#include <iostream>

using namespace std;

typedef struct node
{
    node(): data(0), left(0), right(0){}
    ~node() {
        cout << "deleting: " << data << endl; 
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }

    node* left;
    node* right;

    int data;

} node;

node* new_node(int data) {
    node* n = new node();
    n->data = data;
    return n;
}

// dfs in-order search (Left, Root, Right)
void in_order_print(node* n)
{
    if (!n)
        return;

    in_order_print(n->left);

    cout << n->data << " ";
    
    in_order_print(n->right);
}

// dfs pre-order search (Root, Left, right)
void pre_order_print(node* n)
{
    if (!n)
        return;

    cout << n->data << " ";

    pre_order_print(n->left);

    pre_order_print(n->right);
}

// dfs post-order search (left, Right, Root)

void post_order_print(node* n)
{
    if (!n)
        return;

    post_order_print(n->left);

    post_order_print(n->right);

    cout << n->data << " ";
}

//        1
//      /  \
//     2    3
//    / \
//   4   5
//
// create tree

int main()
{
    node* n = new_node(1);
    n->left = new_node(2);
    n->right = new_node(3);
    n->left->left = new_node(4);
    n->left->right = new_node(5);

    cout << "preorder traversal" << endl;

    pre_order_print(n);
    cout << endl;

    cout << "inorder traversal" << endl;

    in_order_print(n);
    cout << endl;

    cout << "postorder traversal" << endl;

    post_order_print(n);
    cout << endl;

    delete n;

    return 0;
}


