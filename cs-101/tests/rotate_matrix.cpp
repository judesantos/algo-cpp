#include <iostream>

using namespace std;

int main() {

    int m[][4] = { {1,2,3,4}, {6,7,8,9}, {11,12,13,14}, {16,17,18,19} };

    int len = sizeof(m) / sizeof(int);
    int row = sizeof(m) / sizeof(m[0]);
    int col = sizeof(m[0]) / sizeof(m[0][0]);

    cout << "len: " << len << ". row: " << row << ", col: " << col << endl;

    if (!len || (row != col)) {
        cerr << "not a m. exiting.,," << endl;
        return -1;
    }

    // m edge may be row or col, it doesnt matter since its squared anyway.
    int n = row;     

    cout << "Before: " << endl;
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    for (int layer = 0; layer < n/2; layer++) {
        int first = layer;
        int last = n - 1 - layer;

        for (int i = first; i < last; i++) {
            int offset = i - first;

            int top = m[first][i];
            m[first][i] = m[last-offset][first];
            m[last-offset][first] = m[last][last-offset];
            m[last][last-offset] = m[i][last];
            m[i][last] = top;
        }
    }
   
    cout << "After: " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
