#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>

template <class e>
class Stack 
{
    public:
        Stack(int maxsize = 500);
        Stack(const Stack<e> &o);
        ~Stack();

        void push(const e &item);
        e pop();
        const e &peek(int d);

        inline int size() {return this->curElem;}
    protected:
        e *pData;
        int curElem;
        const int maxSize;
};

// class implementation
//

template <class e>
Stack<e>::Stack(int maxsize):
  maxSize(maxsize)
{
    this->pData = new e[this->maxSize];
    this->curElem = 0; 
}

template <class e>
Stack<e>::Stack(const Stack<e> &o)
{
    this->e = o;
}

template <class e>
Stack<e>::~Stack()
{
    delete[] this->pData;
} 

template <class e>
void Stack<e>::push(const e &item)
{
    assert(this->curElem < this->maxSize);
    
    this->pData[this->curElem++] = item;
}

// pop element from top of stack.
//
template <class e>
e Stack<e>::pop()
{
    assert(this->curElem-- > 0);

    return this->pData[this->curElem];
}

template <class e>
const e &Stack<e>::peek(int d)
{
    assert(d > 0 && d <= this->curElem);

    return this->pData[this->curElem - d];
}

#endif // __STACK_H__
