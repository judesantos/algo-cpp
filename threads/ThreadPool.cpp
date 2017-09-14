#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t poolSize):
    m_work(m_ioService),
    m_availableThreads(poolSize)
{
    for (size_t i = 0; i < poolSize; ++i)
    {
        m_threads.create_thread(boost::bind(
            &boost::asio::io_service::run, 
            &m_ioService)
        );
    }
}

ThreadPool::~ThreadPool()
{
    m_ioService.stop();

    try 
    {
        m_threads.join_all();
    } 
    catch (std::exception& e) 
    {
        // log??
    }
}

//template <typename Task>
//void ThreadPool::add_task(Task t)
//{
//    boost::unique_lock<boost::mutex> lock(m_lock);
//
//    if (m_availableThreads == 0) 
//        return;
//
//    --m_availableThreads;
//
//    m_ioService.post(boost::bind(
//        &ThreadPool::task_runner, 
//        this, 
//        boost::function<void()>(t))
//    );
//}

void ThreadPool::task_runner(boost::function<void()> task)
{
    try 
    {
        task();
    } 
    catch(std::exception& e)
    {
        // log error.
    }

    boost::unique_lock<boost::mutex> lock(m_lock);
    ++m_availableThreads;
}
