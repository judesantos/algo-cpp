#include <iostream>

using namespace std;


void do_it(int x) {
    cout << "I did: " << x << endl;
}

typedef void (*func)(int);

typedef void (*func1[3])(int);

void swap(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main() {

    // pointer vars

    int x = 1;
    int * p = &x;
    int ** pp = &p;

    cout << **pp << endl;

    // array of pointers

    int* pa[3] = {0};
    pa[0] = p;

    cout << *pa[0] << endl;

    func f = do_it;

    func f1[3] = {0};
    f1[0] = f;

    f1[0](2);
    //f1[1](3); // will cause app to seg fault;
    f(1);
   
    //array to array of pointers.
    int* l[3] = {0};
    l[0] = p;

    cout << *l[0] << endl;

    char a = 'a';
    char b = 'b';

    swap(a, b);

    cout << "a: " << a << ", b: " << b << endl;

    return 0;
}
