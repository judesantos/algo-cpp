#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <assert.h>

template <class e>
class Queue 
{
    public:
        Queue(int maxsize = 500);
        Queue(const Queue<e> &o);
        ~Queue();

        void enqueue(const e &item);
        e dequeue();

        inline int size() {return this->curElem;}
        
    protected:
        e *pData;
        int curElem;
        const int maxSize;
};

// class implementation
//

template <class e>
Queue<e>::Queue(int maxsize):
  maxSize(maxsize)
{
    this->pData = new e[this->maxSize];
    this->curElem = 0; 
}

template <class e>
Queue<e>::Queue(const Queue<e> &o)
{
    this->e = o;
}

template <class e>
Queue<e>::~Queue()
{
    delete[] this->pData;
} 

template <class e>
void Queue<e>::enqueue(const e &item)
{
    assert(this->curElem < this->maxSize);
    
    this->pData[this->curElem++] = item;
}

// pop element from top of queue.
//
template <class e>
e Queue<e>::queue)
{
    assert(this->curElem-- > 0);

    return this->pData[this->curElem];
}

#endif // __QUEUE_H__
