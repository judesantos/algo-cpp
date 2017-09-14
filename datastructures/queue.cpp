#include <iostream>
#include <stdexcept>

using namespace std;

#define MAX_SIZE 100

template <typename T>
class queue 
{
    public:
        queue(int size = MAX_SIZE); 
        queue(const queue<T>& q);
   
        virtual ~queue();
        
        queue<T>& operator=(const queue<T>& q);
        bool push(T t);
        T pop();

    private:
        void copyT(const queue<T>& s, queue<T>& d);

        T* t;
        
        int size;
        int front;
        int back;

};

template <typename T>
queue<T>::queue(int size):
    size(size),
    front(0),
    back(0)
{
    this->size = this->size ? size : MAX_SIZE;
    this->t = new T[this->size];
}

template <typename T>
queue<T>::~queue()
{
    delete [] this->t;
}

template <typename T>
queue<T>::queue(const queue<T>& q) 
{
    this->size = q.size;
    this->front = q.front;
    this->back = q.back;

    this->t = new T[this->size];

    copyT(q, *this); 
    
}

template <typename T>
queue<T>& queue<T>::operator=(const queue<T>& q) 
{
    if (this->t && (this->size < q.size))
    {
        delete[] this->t;
        this->t = 0;
    }

    if (!this->t) {
        this->t = new T[q.size];
    }

    this->size = q.size;
    this->front = q.front;
    this->back = q.back;

    copyT(q, *this); 
   
    return *this;
}

template <typename T>
bool queue<T>::push(T t) 
{
    this->t[this->back++] = t;

    this->back = this->back % MAX_SIZE;
   
    return true;
}

template <typename T>
T queue<T>::pop()
{
    if (this->front == 0 && this->back == 0)
        return 0; //throw out_of_range("pop out of range exception");

    T t = this->t[this->front++];

    this->front = this->front % MAX_SIZE;

    return t;
}

template <typename T>
void queue<T>::copyT(const queue<T>& s, queue<T>& d) 
{
    if (s.back < s.front) 
    {
        for (int x = s.front; x < MAX_SIZE; x++)
        {
            d.t[x] = s.t[x];
        }
    } 

    for (int y = s.front; y < s.back; y++) {
        d.t[y] = s.t[y];
    }
}

int main() {

    queue<string> q(5);

    q.push("This");
    q.push("is");
    q.push("the");
    q.push("queue");
    q.push("content");
   
    queue<string> q1 = q;
    queue<string> q2(0);
    q2 = q1;

    cout << "q.1: " << q.pop() << endl;
    cout << "q.2: " << q.pop() << endl;
    cout << "q.3: " << q.pop() << endl;
    cout << "q.4: " << q.pop() << endl;
    cout << "q.5: " << q.pop() << endl;

    cout << "q1.1: " << q1.pop() << endl;
    cout << "q1.2: " << q1.pop() << endl;
    cout << "q1.3: " << q1.pop() << endl;
    cout << "q1.4: " << q1.pop() << endl;
    cout << "q1.5: " << q1.pop() << endl;
    
    cout << "q2.1: " << q2.pop() << endl;
    cout << "q2.2: " << q2.pop() << endl;
    cout << "q2.3: " << q2.pop() << endl;
    cout << "q2.4: " << q2.pop() << endl;
    cout << "q2.5: " << q2.pop() << endl;
}
