#include <iostream>

using namespace std;

typedef struct node
{
    node(int data):data(data), next(0){}
    ~node()
    {
        if (next) delete next;
    }

    int data;

    node* next;

} node;

bool is_present(node* n, int t)
{
    node* tmp = n;

    while (tmp) 
    {
        if (tmp->data == t)
        {
            return true;
        }

        tmp = tmp->next;
    }

    return false;
}

node* get_intersection(node* n1, node* n2)
{
    node* u = 0;
    node* ut = 0;       
    node* tmp = 0;

    while (n1) 
    {
        tmp = n2;

        while (tmp)
        {
            if (tmp->data == n1->data) 
            {
                ut = u;

                if (!is_present(u, n1->data))
                {
                    u = new node(n1->data);
                    u->next = ut;
                }

                break;
            }
            
            tmp = tmp->next;
        }

        n1 = n1->next;
    }

    return u;
}

node* get_union(node* n1, node* n2)
{
    node* itx = 0;
    node* tmp = n1;

    // fill result list with items from first list.
    do
    {
      node* u = itx;
      itx = new node(tmp->data);
      itx->next = u;

      tmp = tmp->next;
    } while (tmp);

    tmp = n2;

    // add unique items to result from second list.
    do 
    {
        node* ut = itx;

        if (!is_present(itx, tmp->data))
        {
            itx = new node(tmp->data);
            itx->next = ut;
        }
        tmp = tmp->next;
    } while (tmp);

    return itx;
}

int main()
{
    node* l1 = new node(10);
    l1->next = new node(15);
    l1->next->next = new node(4);
    l1->next->next->next = new node(20);

    node* l2 = new node(8);
    l2->next = new node(4);
    l2->next->next = new node(2);
    l2->next->next->next = new node(10);

    node* result = get_union(l1, l2);
    node* tmp = result;

    cout << "union: " << endl;

    while (tmp) 
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }

    delete result;
    cout << endl;

    result = get_intersection(l1, l2);
    tmp = result;

    cout << "intersection: " << endl;

    while (tmp) 
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }

    cout << endl;

    delete result;
    delete l1;
    delete l2;

    return 0;
}

