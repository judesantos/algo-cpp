#include <iostream>
#include <exception>
#include <vector>

using namespace std;

template <typename T>
struct node {
    node(T data):data(data),next(0){}
    ~node() {
        cout << "deleting " << data << endl; 
    }

    node<T>* next;
    
    T data;
};

template <typename T>
struct stack {
    stack(): top(0), size(0){}
    virtual ~stack() {
        clear();  
    }

    node<T>* top;
    int size;

    /**
     * push
     */
    virtual void push(T data) {

        node<T>* n = new node<T>(data);
        n->next = top;
        top = n;

        size++;
    }

    /**
     * pop
     */
    virtual T pop()  {
        if (!top)
            throw ios_base::failure("stack empty");

        node<T>* t = top;
        top = top->next;

        int data = t->data;
        delete t;

        size--;

        return data;
    }

    /**
     * peek
     */
    T peek() throw(exception) {
        if (!top)
            throw ios_base::failure("stack empty");
        
        return top->data;
    }

    /**
     * is_empty
     */
    bool is_empty() {
        return !top;
    }

    void clear() {

        if (!top)
            return;
        
        node<T>* t = top;

        while (t) {
            top = t->next;
            delete t;
            t = top;
        }
    }

    int get_size() {
        return size;
    }
};

template <typename T>
struct set_of_stacks {
    
    int treshold;
    vector<stack<T>* > stacks;

    set_of_stacks(int treshold):treshold(treshold){}
    ~set_of_stacks() {
        clear();
    }

    stack<T>* get_stack() {

        if (stacks.size() == 0) {
            stacks.push_back(new stack<T>());
        }

        stack<T>* s = stacks[stacks.size()-1];

        if (s->get_size() == treshold) {
            stacks.push_back(new stack<T>());
            s = stacks[stacks.size()-1]; 
        } 
        else if (stacks.size() > 1 && s->get_size() == 0) 
        {
            stacks.pop_back();
            s = stacks[stacks.size()-1]; 
        }
        
        return s;
    }

    void push(T data) {
        stack<T>* s = get_stack();
        s->push(data);
    }

    T pop() {
        stack<T>* s = get_stack();
        return s && s->get_size() ? s->pop() : -1;
    }

    void clear() {

        while(stacks.size()) {
            delete stacks[stacks.size()-1];
            stacks.pop_back();
        }
    }

    /**
     * pop stack at specified sub-stack
     */
    T pop_at(int index) {
        if (index >= stacks.size()) {
            throw ios_base::failure("stack error: no substack found in index");
        }

        stack<T>* t = stacks[index];

        return t->pop();
    }
};

int main() {

    set_of_stacks<int> ss(2);

    ss.push(1);
    ss.push(2);
    ss.push(3);

    ss.pop_at(0);
    //cout << "popAt(0) : " << ss.pop_at(0) << endl;
    //ss.pop();
    //ss.pop();
    //ss.pop();
    
    return 0;
}
