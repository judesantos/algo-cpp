#include <iostream>

using namespace std;

/**
 *  find using binary search a value in a rotated array.
 */

/**
 * find by binary search a sorted array.
 *
 */

// recursive - return index where value was found.
int bsearch_sorted_recursive(int a[], int start, int end, int val) {
    
    if (start >= end)
        return -1;
    
    int mid = start + (end - start)/2;
    
    if (val == a[mid])
        return mid;
    
    if (val > mid)
        return bsearch_sorted_recursive(a, mid+1, end, val);
    else
        return bsearch_sorted_recursive(a, start, mid-1, val);
}

int main() {

    int a[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(a) / sizeof(a[0]);
    
    int val = 8;

    cout << "found " << val << " at index: " << bsearch_sorted_recursive(a, 0, len, val) << endl;

    return 0;
}
