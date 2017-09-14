#include <iostream>

using namespace std;

/**
 * make fibonacci series using iterative and recursive solution.
 * using dynamic programming.
 */

void fibo_iterative(int num) {
    
    int curr = 0;
    int prev = 0;

    while (curr < num) {

        cout << curr << " ";

        if (curr == 0) {
            curr = 1;
            continue;
        }

        curr = curr + prev;
        prev = curr - prev;
    }
}

// bottom up
void fibo_recursive(int num, int prev, int curr) {

    if (num < curr)
        return;

    cout << curr << " ";

    if (curr == 0)
        prev = 1;

    fibo_recursive(num, curr, prev+curr);
}

int main() {

    cout << "iterative. n=100:" << endl;

    fibo_iterative(100);

    cout << endl;

    cout << "recursive. n=100:" << endl;

    fibo_recursive(100, 0, 0);


    return 0;
}
