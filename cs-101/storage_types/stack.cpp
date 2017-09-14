#include <iostream>
#include <exception>

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
    stack(): top(0){}
    virtual ~stack() {
        clear();  
    }

    node<T>* top;

    /**
     * push
     */
    virtual void push(T data) {

        node<T>* n = new node<T>(data);
        n->next = top;
        top = n;
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

};

template <typename T>
struct stack_min: public stack<T> {
    stack_min(){}
    ~stack_min() {
        mins.clear();
    }

    stack<T> mins;
    
    void push(T data) {

        if (mins.is_empty()) {
            mins.push(data);
        } else {
            if (mins.peek() > data) {
                mins.push(data);
            }
        }
        
        stack<T>::push(data);
    }
    T pop() {
        T t = stack<T>::pop();

        if (mins.peek() == t) {
            mins.pop();
        }

        return t;
    }

    T min() {
        return mins.peek();
    }
};

int main() {

    stack_min<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "min: " << s.min() << endl;
    cout << "pop: " << s.pop() << endl;
    cout << "min: " << s.min() << endl;
    cout << "pop: " << s.pop() << endl;
    cout << "min: " << s.min() << endl;
    cout << "pop: " << s.pop() << endl;

    return 0;
}
