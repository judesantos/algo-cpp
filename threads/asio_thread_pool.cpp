#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/move/move.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;
namespace asio = boost::asio;

typedef struct _atay_t {
    int tid;
    int data;
} atay_t;

int run(atay_t& t) 
//int run(int t) 
{
    cout << t.tid << "Going to sleep (" << t.data << ")" << endl;
    sleep(t.data);
    cout << "wake up (" << t.data << ")" << endl;

    //cout << t << ". Going to sleep (" << t << ")" << endl;
    //sleep(t);
    //cout << "wake up (" << t << ")" << endl;

    return 0;
}

typedef boost::packaged_task<atay_t&> task_t;
//typedef boost::packaged_task<int> task_t;
typedef boost::shared_ptr<task_t> ptask_t;

void push_task(atay_t& t, boost::asio::io_service& io, vector<boost::shared_future<atay_t&> >& data)
{
    ptask_t task = boost::make_shared<task_t>(boost::bind(&run, t));
    boost::shared_future<atay_t&> future(task->get_future());
    data.push_back(future);
    io.post(boost::bind(&task_t::operator(), task));
}

//void push_task(int t, boost::asio::io_service& io, vector<boost::shared_future<int> >& data)
//{
//    ptask_t task = boost::make_shared<task_t>(boost::bind(&run, t));
//    boost::shared_future<int> future(task->get_future());
//    data.push_back(future);
//    io.post(boost::bind(&task_t::operator(), task));
//}

int main() {
    
    boost::asio::io_service io_service;
    boost::thread_group threads;
    boost::asio::io_service::work work(io_service);

    // for (int i = 0; i < (int)boost::thread::hardware_concurrency(); ++i)
    for (int i = 0; i < 3; ++i)
    {
        threads.create_thread(boost::bind(&asio::io_service::run, &io_service));
    }

    vector<boost::shared_future<atay_t&> > pending_data;
    //vector<boost::shared_future<int> > pending_data;

  
    atay_t t;
    t.tid = 0;
    t.data = 1;

    run(t);

    atay_t t1;
    t1.tid = 1;
    t1.data = 1;
    atay_t t2;
    t2.tid = 2;
    t2.data = 2;
    atay_t t3;
    t3.tid = 3;
    t2.data = 3;

    push_task(t1, io_service, pending_data);
    push_task(t2, io_service, pending_data);
    push_task(t3, io_service, pending_data);
    push_task(t1, io_service, pending_data);
    push_task(t2, io_service, pending_data);
    push_task(t3, io_service, pending_data);
    push_task(t1, io_service, pending_data);
    push_task(t2, io_service, pending_data);
    push_task(t3, io_service, pending_data);

//    push_task(1, io_service, pending_data);
//    push_task(2, io_service, pending_data);
//    push_task(3, io_service, pending_data);
//    push_task(1, io_service, pending_data);
//    push_task(2, io_service, pending_data);
//    push_task(3, io_service, pending_data);
//    push_task(1, io_service, pending_data);
//    push_task(2, io_service, pending_data);
//    push_task(3, io_service, pending_data);
    

    boost::wait_for_all(pending_data.begin(), pending_data.end());

    return 0;
}
