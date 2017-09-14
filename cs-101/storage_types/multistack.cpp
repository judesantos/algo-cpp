#include <iostream>

using namespace std;

// a multistack using a single array
//
class multi_stack {

private:
    int num_stacks;
    int stack_size;
    int* stacks;
    int* sizes;

public:
    /**
     *  num_stacks - number of stacks to create
     *  stack_size - size of each stack
     */
    multi_stack(int num_stacks, int stack_size):
        num_stacks(num_stacks),
        stack_size(stack_size)
    {
        stacks = new int[num_stacks * stack_size];
        sizes = new int[num_stacks];
    }

    ~multi_stack() {
        delete [] stacks;
        delete [] sizes;
    }

    /*
     * is_full
     */
    bool is_full(int stack_id) {
        if (num_stacks < stack_id || stack_id <= 0)
            throw ios_base::failure("stack error: no such stack");

        return sizes[stack_id-1] == stack_size;
    }
    
    /*
     * is_empty
     */
    bool is_empty(int stack_id) {
        if (num_stacks < stack_id || stack_id <= 0)
            throw ios_base::failure("stack error: no such stack");

        return sizes[stack_id-1] == 0;
    }

    /*
     * offset - stack start offset
     */
    int offset(int stack_id) {
        if (num_stacks < stack_id || stack_id <= 0)
            throw ios_base::failure("stack error: no such stack");
        
        return (stack_id-1) * this->stack_size;
    }

    /*
     * push
     */
    void  push(int stack_id, int data) {
        if (is_full(stack_id)) 
            throw ios_base::failure("stack error: stack is full.");
        
        int* p = stacks + (offset(stack_id) + sizes[stack_id-1]++);

        *p = data;

        cout << "add node " << stack_id << ", data: " << data << endl;
    }

    /*
     * pop
     */
    int pop(int stack_id) {
        if (is_empty(stack_id))
            throw ios_base::failure("stack error: stack is empty.");
         
        int* p = stacks + (offset(stack_id) + --sizes[stack_id-1]);

        cout << " pop node " << stack_id << ", data: " << *p << endl;

        return *p;
    }
    
    /*
     * peek
     */
    int peek(int stack_id) {
        return stacks[offset(stack_id)];
    }
};

int main() {

    multi_stack ms(3, 5);

    ms.push(1, 1);
    ms.push(1, 2);
    ms.push(1, 3);
    ms.push(1, 4);
    ms.push(1, 5);

    ms.push(2, 1);
    ms.push(2, 2);
    ms.push(2, 3);
    ms.push(2, 4);
    ms.push(2, 5);

    ms.push(3, 1);
    ms.push(3, 2);
    ms.push(3, 3);
    ms.push(3, 4);
    ms.push(3, 5);

    cout << "pop " << ms.pop(1) << endl;
    cout << "pop " << ms.pop(1) << endl;
    cout << "pop " << ms.pop(1) << endl;
    cout << "pop " << ms.pop(1) << endl;
    cout << "pop " << ms.pop(1) << endl;

    cout << "pop " << ms.pop(2) << endl;
    cout << "pop " << ms.pop(2) << endl;
    cout << "pop " << ms.pop(2) << endl;
    cout << "pop " << ms.pop(2) << endl;
    cout << "pop " << ms.pop(2) << endl;

    cout << "pop " << ms.pop(3) << endl;
    cout << "pop " << ms.pop(3) << endl;
    cout << "pop " << ms.pop(3) << endl;
    cout << "pop " << ms.pop(3) << endl;
    cout << "pop " << ms.pop(3) << endl;

    return  0;
}
