#include <iostream>

using namespace std;

typedef struct node
{
    node(int data):data(data),left(0),right(0){}
    ~node()
    {
        if (left) delete left;
        if (right) delete right;
    }

    int data;

    node* left;
    node* right;
} node;

node* new_node(int data)
{
    return new node(data);
}

void find_min_max(node* n, int* min, int* max, int hd)
{
    if (!n)
        return;

    if (*min > hd)
        *min = hd;
    if (*max < hd)
        *max = hd;

    find_min_max(n->left, min, max, hd-1);
    find_min_max(n->right, min, max, hd+1);
}

void print_vertical_order(node* n, int line, int hd)
{
    if (!n)
        return;

    if (line == hd)
        cout << n->data << " ";

    print_vertical_order(n->left, line, hd-1);
    print_vertical_order(n->right, line, hd+1);
}

int main()
{
    node* root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);
    root->right->right->right = new_node(9);
    root->right->left->right = new_node(8);

    int min = 0, max = 0;

    find_min_max(root, &min, &max, 0);

    for (int i = min; i <= max; i++)
    {
        print_vertical_order(root, i, 0);

        cout << endl;
    }
    
    delete root;

    return 0;
}

