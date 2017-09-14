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
        top = top->next ? top->next : 0;

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
struct stack_sort: public stack<T> {
    
    stack_sort():sorted(0){}
    ~stack_sort() {
        if (sorted) delete sorted;
    }

    stack<T>* sorted;

    /**
     * sort - Ascending. use sorted stack as tmp sorting 
     *        store, then push back sorted values in main stack once completed.
     */
    void sort() {
        if (this->is_empty())
            return;

        if (!sorted)
            sorted = new stack<T>();

        while(!this->is_empty()) {
            // store values in 'sorted' stack in descending order.

            // get next value from main stack. hold this for a while, while
            // were determining where it should go in the sorted stack.
            T val = this->pop();
            // Push higher values back into main stack when it has to 
            // make way for lower value 'val'. 
            while (!sorted->is_empty()) {
                if (val < sorted->peek())
                    this->push(sorted->pop());
                else
                    break;
            }
            // 'val' is now positioned descending relative 
            // to the old nodes in the stack. 
            sorted->push(val);

            // Go back to main stack and process more values, 
            // starting with items  we swapped out of sorted earlier.
        }

        // Put back sorted values into main stack, ascending.
        while(!sorted->is_empty()) {
            this->push(sorted->pop());
        }
    }
};

int main() {
    
    stack_sort<int> ss;

    ss.push(3);
    ss.push(10);
    ss.push(5);
    ss.push(7);

    ss.sort();

    cout << "pop " << ss.pop() << endl;
    cout << "pop " << ss.pop() << endl;
    cout << "pop " << ss.pop() << endl;
    cout << "pop " << ss.pop() << endl;

    return 0;
}

