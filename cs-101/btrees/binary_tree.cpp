#include <iostream>

//using namespace std;

template <typename T>
class node 
{
    public:
      node():left(0), right(0) {}
      virtual ~node(){}

      T data;

      node<T>* left;
      node<T>* right;
};

template <typename T>
class binary_tree
{
    public:
        binary_tree();
        virtual ~binary_tree();

        node<T>& push(T t);
        node<T>& find(T t);
        T remove(T t);
    
        node<T>& getRoot() { return *this->root; }
        
        void empty();

    private:
        node<T>& insert(node<T>* n, T t);
        node<T>& deleteNode(node<T>* n, T t);
        node<T>& minNode(node<T>* n);

        node<T>* root;
};

template <typename T>
binary_tree<T>::binary_tree():
    root(0)
{
}

template <typename T>
binary_tree<T>::~binary_tree()
{
    this->empty();
}

template <typename T>
void binary_tree<T>::empty()
{
    node<T>* n = &this->getRoot();

    while (n) 
    {
        n = &this->deleteNode(n, n->data);
    }
}

template <typename T>
node<T>& binary_tree<T>::push(T t)
{
    if (!this->root)
    {
        this->root = new node<T>();
        this->root->data = t;
        
        return *this->root;
    }

    return this->insert(this->root, t);    
}

template <typename T>
node<T>& binary_tree<T>::insert(node<T>* n, T t)
{
    if (!n)
    {
        n = new node<T>();
        n->data = t;
        return *n;
    }
    
    if (n->data > t)
    {
        n->left = &this->insert(n->left, t);
    }
    else
    {
        n->right = &this->insert(n->right, t);
    }

    return *n;
}

template <typename T>
T binary_tree<T>::remove(T t)
{
    node<T>* n = this->deleteNode(this->root, t);
    if (!n) {
        return 0;
    }

    return n->data;
}
  
template <typename T>
node<T>& binary_tree<T>::deleteNode(node<T>* n, T t)
{
    node<T>* tmp = 0;

    if (!n) {
        return *n;
    }

    if (t < n->data) 
    {
        n->left = &this->deleteNode(n->left, t);
    } 
    else if (t > n->data)
    {
        n->right = &this->deleteNode(n->right, t);
    }
    else 
    {
        if (!n->left)
        {
            tmp = n->right;
            delete n;
            return *tmp;
        }
        else if (!n->right)
        {
            tmp = n->left;
            delete n;
            return *tmp;
        }

        tmp = &this->minNode(n->right);
        n->data = tmp->data;

        n->right = &this->deleteNode(n->right, tmp->data);
    }

    return *n;
}

template <typename T>
node<T>& binary_tree<T>::minNode(node<T>* n)
{
    node<T>* tmp = n;
    
    while(tmp->left) {
        tmp = tmp->left;
    }

    return *tmp;
}

//void print_in_order(node<int>* n) 
//{
//    if (n)
//    {
//        print_in_order(n->left);
//        cout << n->data << endl;
//        print_in_order(n->right);
//    }
//}

//int main()
//{
//    binary_tree<int> bt;
//
//    bt.push(100);
//    bt.push(1);
//    bt.push(2);
//    bt.push(99);
//    bt.push(80);
//    bt.push(77);
//    bt.push(65);
//    bt.push(54);
//
//    node<int>* n = &bt.getRoot();
//
//    print_in_order(n);
//
//    return 0;
//}
