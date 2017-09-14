#ifndef __BOOST_THREAD_POOL_H__
#define __BOOST_THREAD_POOL_H__

#include <boost/thread.hpp>
#include <boost/asio.hpp>

using namespace std;

class ThreadPool
{
    public:
        ThreadPool(size_t poolSize);
        ~ThreadPool();

        template <typename Task>
        inline void add_task(Task t)
        {
            boost::unique_lock<boost::mutex> lock(m_lock);

            if (m_availableThreads == 0) 
                return;

            --m_availableThreads;

            m_ioService.post(boost::bind(
                &ThreadPool::task_runner, 
                this, 
                boost::function<void()>(t))
            );
        }

    private:
        void task_runner(boost::function<void()> task);        
        
        boost::asio::io_service m_ioService;
        boost::asio::io_service::work m_work;
        boost::thread_group m_threads;

        size_t m_availableThreads;
        boost::mutex m_lock;

};


#endif // __BOOST_THREAD_POOL__ 
