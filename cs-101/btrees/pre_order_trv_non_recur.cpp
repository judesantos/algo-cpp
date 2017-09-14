#include <iostream>

using namespace std;

typedef struct node
{
    node(int data):data(data), left(0), right(0){}
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

void morris_traversal(node* root)
{
    if (!root)
        return;

    node *pre, *current = root;

    while (current)
    {
        if (!current->left)
        {
            cout << current->data << endl;
            current = current->right;
        }
        else 
        {
            
            pre = current->left;
            while (pre->right && pre->right != current)
            {
                pre = pre->right;
            }

            if (!pre->right)
            {
                cout << current->data << endl;

                pre->right = current; 
                current = current->left;
            }
            else
            {
                current = current->right;
            }

        }
    }
    
}

int main()
{
    node* root = new_node(1);

    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    morris_traversal(root);

    delete root;

    return 0;
}
