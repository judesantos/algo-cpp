#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef struct node
{
    node(int data): data(data), left(0), right(0){}
    ~node()
    {
        if (left) delete left;
        if (right) delete right;
    }

    int data;

    node* left;
    node* right;
} node;

void get_vertical_order(node* n, int hd, map<int, vector<int> > &m)
{
    if (!n)
        return;

    m[hd].push_back(n->data);
    
    get_vertical_order(n->left, hd-1, m);
    get_vertical_order(n->right, hd+1, m);
}

void print_vertical_order(node* n)
{
    map<int, vector<int> > m;
    int hd = 0;

    get_vertical_order(n, hd, m);

    map<int, vector<int> >::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    
    print_vertical_order(root);

    delete root;

    return 0;
}
