#include <iostream>

using namespace std;

#define MAX 1000

/**
 * given an array, find 2 vales that is equal to a given sum.
 *
 * Implement in linear time.
 *
 *  Cs: O(n)
 *  Ct: O(n)
 */

void get_pairs(int a[], int len, int sum) {

    if (len <= 0) {
        cout << "invalid length, exit" << endl;
        return;
    }

    int diff = 0;
    bool map[MAX] = {0};

    for (int i = 0; i < len; ++i) {
        
        if (a[i] > MAX || a[i] <= 0) {
            cout << "invalid array value: " << a[i] << ", exiting," << endl;
            return;
        }

        diff = sum - a[i];

        if (diff > 0 && a[diff]) {
            cout << "sum of " << sum << " (" << a[i] << ", " << diff << endl;
        }

        map[a[i]] = true;
    }
}

int main() {

    int sum = 10;

    /**
     * Test cases
     */

    // T1: 0 < m
    cout << "T1:" << endl;

    int a[] = {-1, 2, 5, 8, 7, 3};
    int len = sizeof(a) / sizeof(a[0]);

    get_pairs(a, len, sum);

    
    // T2: MAX < m
    cout << "T2:" << endl;

    int b[] = {10000, 2, 5, 8, 7, 3};
    len = sizeof(b) / sizeof(b[0]);

    get_pairs(b, len, sum);


    // T3: 0 < m <= 1000
    cout << "T3:" << endl;

    int c[] = {1, 2, 5, 8, 7, 3};
    len = sizeof(c) / sizeof(c[0]);

    get_pairs(c, len, sum);

    return 0;
}
