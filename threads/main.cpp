#include <iostream>
#include "ThreadPool.h"

using namespace std;

// example routine to use the threadpool

// function pointer task
void work() {
    cout << "function pointer worker reporting!!" << endl;
}

// object worker task. implements operator().
class Worker
{
    public:
        void operator()() {
            cout << "Object worker reporting!!" << endl;
        }
};

// function pointer with params.
void more_work(int x)
{
    cout << "function pointer with param x = " << x << ", reporting!!" << endl;
}

int main() 
{
    ThreadPool tp(2);

    tp.add_task(work);
    tp.add_task(Worker());
    tp.add_task(boost::bind(more_work, 5));
    tp.add_task(boost::bind(more_work, 6));
    tp.add_task(boost::bind(more_work, 7));

    return 0;            
}

