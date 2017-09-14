#ifndef __BOOST_THREAD_POOL_H__
#define __BOOST_THREAD_POOL_H__

#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace boost;
using namespace std;

class ThreadPool
{
    public:
        inline ThreadPool(size_t poolSize);
        ~ThreadPool();

        inline template <typename Task>
        void run_task(Task t);

    private:
        inline void task_runner(function<void()> task);        
        
        asio::io_service m_ioService;
        asio::io_service::work m_work;
        thread_group m_threads;
        size_t m_availableThreads;
        mutex m_lock;

};

ThreadPool::ThreadPool(size_t poolSize):
    m_work(m_ioService),
    m_availableThreads(poolSize)
{
    for (size_t i = 0; i < poolSize; ++1)
    {
        m_threads.create_thread(bind(asio::io_service::run, &m_ioService));
    }
}

ThreadPool::~ThreadPool()
{
    m_ioService.stop();

    try 
    {
        m_threads.join();
    } 
    catch (exception& e) 
    {
        // log??
    }
}

template <typename Task>
void ThreadPool::run_task(Task t)
{
    unique_lock<mutex> lock(m_lock);

    if (m_availableThreads == 0) 
        return;

    --m_availableThreads;

    m_ioService.post(bind(&ThreadPool::task_runner, this, function<void>(t)));
}

void ThreadPool::task_runner(function<void()> task)
{
    try 
    {
        task();
    } 
    catch(const exception& e)
    {
        // log error.
    }

    unique_lock<mutex> lock(m_lock);
    ++m_availableThreads;
}

#endif // __BOOST_THREAD_POOL__ 
