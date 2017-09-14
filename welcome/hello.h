// hello.h
//
#ifndef __HELLO_H__
#define __HELLO_H__

#include <string>

using namespace std;

class Hello {

    public:
        Hello(string msg);
        ~Hello();

        string sayHello();

    private:

        string msg;

};

#endif // __HELLO_H__
