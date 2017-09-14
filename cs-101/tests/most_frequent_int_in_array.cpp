#include <iostream>
#include <unordered_map>

using namespace std;

/**
 *  Given an array of ints, find out which int 
 *  is repeating the most number of times.
 *
 *  complexity:
 *   space(Cs): O(n)
 *   time(Ct): O(n)
 */

int most_frequent_int(int a[], int len) {
    
    if (len <= 0)
        return -1;

    unordered_map<int, int> db;

    int most_frequent = 0;
    int freq_count = 0;

    for (int i = 0; i < len; ++i) {
        if(freq_count < ++db[a[i]]) {
            freq_count = db[a[i]];
            most_frequent = a[i];
        }
    }

    return most_frequent;
}

int main() {

    int a[] = {3, 5, 7, 5, 4, 3, 1, 3, 2};
    int len = sizeof(a) / sizeof(a[0]);

    cout << "most frequent number: " << most_frequent_int(a, len) << endl; 

    return 0;
}
