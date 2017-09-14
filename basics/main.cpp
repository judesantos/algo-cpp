#include <iostream>

using namespace std;

class X 
{
    public:
        virtual void hello() { cout << "hello from base" << endl; }
};

class Y: public X
{
    public:
        inline void hello() { 
            X::hello(); 
            cout << "Hello from child" << endl; }
};

int main() 
{

    //X x;
    Y y;
    X &x = y;
    x.hello();

    return 0;
}
