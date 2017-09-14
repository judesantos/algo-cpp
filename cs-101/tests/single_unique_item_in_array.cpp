#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Find a single unique value in the array.
 *
 */ 

void find_unique_value(int a[], int len) {
   
    if (len <= 0)
        return;

    unordered_map<int, int> m;
    unordered_map<int, int>::iterator it;

    for (int i = 0; i < len; ++i) 
        m[a[i]]++;
    
    it = m.begin();

    while (it != m.end()) {
        if (it->second == 1) {
            cout << "found: " << it->first << endl;
            break;
        }
        it++;
    }
}

int main() {

    int a[] = {1,2,1,2,3,4,4};
    int len = sizeof(a) / sizeof(a[0]);

    find_unique_value(a, len);

    return 0;
}
