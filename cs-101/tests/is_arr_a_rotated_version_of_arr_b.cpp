#include <iostream>

using namespace std;

/*
 * given 2 arrays, check if 2nd array is a rotated version of the other.
 *
 * Cs: O(1)
 * Ct: O(n+m):
 */
bool is_rotated_version(int a[], int alen, int b[], int blen) {

    if (alen != blen)
        return false;

    bool start_found = false;
    int j = 0;
    
    for (int i = 0; i < blen; ++i) {

        while (j < alen*2) {

            int idx = j++ % alen;

            if (a[idx] == b[i]) {
                start_found = true;
                break;
            }

            if (!start_found)
                continue;
            else {
                start_found = false;
                break;
            }
        }
        
        if (!start_found)
            break;
    }

    return start_found;
}

int main() {
    
    int a[] = {1,1,3,1,5,1,2};
    int b[] = {3,1,5,1,2,1,1};

    int la = sizeof(a) / sizeof(a[0]);
    int lb = sizeof(b) / sizeof(b[0]);

    cout << "is b rotation of a? " << (is_rotated_version(a, la, b, lb) ? "yes" : "no") << endl;

    return 0;
}

