#include <iostream>

using namespace std;

typedef struct node 
{
    node(): data(0), left(0), right(0){}
    ~node() {
        if (left) delete left;
        if (right) delete right;
    }

    int data;

    node* left;
    node* right;
} node;

node* new_node(int data)
{
    node* n = new node();
    n->data = data;
    return n;
} 

int height(node* n)
{
    if (!n)
        return 0;

    int lhgt = height(n->left);
    int rhgt = height(n->right);

    if (lhgt > rhgt)
        return lhgt + 1;
    else
        return rhgt + 1;
}

void print_level(node* n, int level)
{
    if (!n)
        return;

    if (level == 1) {
        cout << n->data << " ";
    }
    else 
    {
        print_level(n->left, level-1);
        print_level(n->right, level-1);
    }
}

int main()
{
    node* root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    
    int h = height(root);

    for (int i = 1; i <= h; i++)
    {
        print_level(root, i);
    }
    
    delete root;
    return 0;
}

