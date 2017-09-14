#include <iostream>

using namespace std;

typedef struct node
{
    node(int data):data(data), left(0), right(0){}
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
    return new node(data);
}

// iterative approach to tree traversal using morris' method.
void morris_traversal(node* root)
{
    if (!root)
        return;

    node *pre, *current = root;

    while(current)
    {
        if (!current->left)
        {
            cout << current->data << endl;
            current = current->right;
        }
        else
        {
            // go down to the leftmost node             
            pre = current->left;
            while (pre->right && pre->right != current)
            {
                pre = pre->right;
            }

            if (!pre->right)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                // we've made a full circle and now were ready to
                // process the next node at right of current.
            
                cout << current->data << endl;

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

