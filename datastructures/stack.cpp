#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 100

template <typename T>
class stack {
    public:
        stack(int size = MAX_SIZE);
        stack(const stack<T>& s);
        stack<T>& operator=(const stack<T>& s);
        
        virtual ~stack();

        bool push(T t);
        T pop();

        int get_size() { return this->top > 0 ? this->top - 1 : 0; }
    
    private:
        T* t;
        int top;     
        int size;
};

template <typename T>
stack<T>::stack(int size):
    size(size),
    top(-1)
{
    this->t = new T[size];
}

template <typename T>
stack<T>::~stack()
{
    delete[] this->t;
}

template <typename T>
stack<T>::stack(const stack<T>& s)
{
    this->size = s.size;
    this->top = s.top;

    this->t = new T[this->size];

    for(int x = 0; x < this->top; x++)
    {
        this->t[x] = s.t[x];
    }
}

template <typename T>
stack<T>& stack<T>::operator=(const stack<T>& s)
{
    if (this == &s)
        return *this;

    if (this->t && (this->size < s.size)) {
        delete[] this->t;
        this->t = 0;
    }

    this->size = s.size;
    this->top = s.top;
    
    if (!this->t) {
        this->t = new T[this->size];
    }
    
    for(int x = 0; x < this->top; x++)
        this->t[x] = s.t[x];
    
    return *this;
}

template <typename T>
bool stack<T>::push(T t) {
    if (this->size < this->top)
        return false;

    this->t[++this->top] = t;

    return true;
}

template <typename T>
T stack<T>::pop()
{
    if (this->top < 0)
        throw out_of_range("pop out of range exception");

    return this->t[this->top--];
}


int main() {
    stack<string> s(10);
    
    s.push("this");
    s.push("is");
    s.push("string");

    stack<string> s1 = s;
    stack<string> s2 = s;
    stack<string> s3(5);
    s3 = s2;

   cout << "s.size: " << s.get_size()  << endl;
   
   cout << "s1: " << s.pop() << endl;
   cout << "s2: " << s.pop() << endl;
   cout << "s3: " << s.pop() << endl;

   cout << "size: " << s.get_size() << endl;

   cout << "s1.size: " << s1.get_size()  << endl;

   cout << "s1: " << s1.pop() << endl;
   cout << "s2: " << s1.pop() << endl;
   cout << "s3: " << s1.pop() << endl;

   cout << "s2.size: " << s2.get_size()  << endl;

   cout << "s1: " << s2.pop() << endl;
   cout << "s2: " << s2.pop() << endl;
   cout << "s3: " << s2.pop() << endl;

   
   cout << "s3.size: " << s3.get_size()  << endl;

   cout << "s1: " << s3.pop() << endl;
   cout << "s2: " << s3.pop() << endl;
   cout << "s3: " << s3.pop() << endl;
}
