#include <iostream>
#include <map>

using namespace std;

void find_sym_pairs(int (*arr)[2], int len)
{
    map<int, int> m;

    for (int i = 0; i < len; i++) {
        int key = arr[i][0];
        int val = arr[i][1];

        int mval = -1;
        
        map<int, int>::iterator it = m.find(val);

        if (it != m.end()) {
            mval = it->second;
        }

        if (mval >= 0 && mval == key)
            cout << "(" << val << ", " << key << ")" << endl;
        else
            m.insert(pair<int, int>(key, val));
    }
}

int main()
{

    int arr[5][2] = {{11, 20}, {30, 40}, {5, 10}, {40, 30}, {10, 5}};

    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i][0] == arr[j][1] && arr[i][1] == arr[j][0])
                cout << "pairs at index: " << i << " and " << j << endl;
        }
    }

    cout << endl << "Using hashmap:" << endl;

    find_sym_pairs(arr, len);

    return 0;
}
