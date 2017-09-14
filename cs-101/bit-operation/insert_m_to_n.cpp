#include <iostream>
#include <math.h>

using namespace std;

int main() {

    // 1100
    // 76

    int i = 2;
    int j = 6;

    int n = (1 << 10) + 32; // 1056
    int m = 19;

    cout << "m: " << m << endl;
    cout << "n: " << n << endl;

    m = (m << i);
    
    cout << "m: " << m << endl;

    int left = ~0 << j + 1;
    int right = (1 << i);
    
    cout << "right: " << right << endl;

    right -= 1;

    int mask = left | right;

    n = n & mask;
    n = n | m;

    cout << n << endl;

    return 0;
}
