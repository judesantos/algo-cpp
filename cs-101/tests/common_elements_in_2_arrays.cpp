#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Find the intersection between 2 sets
 */
void common_values_in_arrays(int a[], int alen, int b[], int blen) {

    if (alen <= 0 || blen <= 0) {
        cout << "Invalid array length, quit" << endl;
        return;
    }
    
    unordered_map<int, int> m;
    unordered_map<int, int>::iterator it;

    for (int i = 0; i < alen; ++i) {
        m[a[i]]++;
    }

    for (int j = 0; j < blen; ++j) {
        m[b[j]]++;
    }

    it = m.begin();

    while (it != m.end()) {

        if (it->second > 1) {
            cout << it->first << " ";
        }
        it++;
    }

    cout << endl;
}

int main() {

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};

    int alen = sizeof(a) / sizeof(a[0]);
    int blen = sizeof(b) / sizeof(b[0]);

    cout << "intersections of a and b: " << endl;

    common_values_in_arrays(a, alen, b, blen);

    return 0;
}
