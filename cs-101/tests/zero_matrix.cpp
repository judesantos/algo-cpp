#include <iostream>
#include <memory.h>

using namespace std;

// search matrix for values set to 0, if so set entire row and cols to 0

/**
 * args.:
 *  m - the 2d array
 *  row - matrix row width
 *  col - col to zero out
 */
void setColToZero(int* m, int row, int col) {
    
    for (int i = 0; i < row; i++) {
        *((m+i*row) + col) = 0;
    }
}

/**
 * args.:
 *  m - the 2d array
 *  row - matrix row width
 *  col - matrix column width
 *  zrow - row to zero out
 */
void setRowToZero(int* m, int row, int col, int zrow) {
    
    for (int i = 0; i < col; i++) {
        *((m+row*zrow) + i) = 0;
    }
}

int main() {

    int m[][4] = { {0,2,3,4}, {6,7,8,9}, {1,2,3,4}, {6,7,8,0} };

    int len = sizeof(m) / sizeof(int);
    int row = sizeof(m) / sizeof(m[0]);
    int col = sizeof(m[0]) / sizeof(m[0][0]);

    cout << "len: " << len << ". row: " << row << ", col: " << col << endl;

    if (!len || (row != col)) {
        cerr << "not a m. exiting.,," << endl;
        return -1;
    }

    cout << "Before: " << endl;
   
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    bool z_rows[row];
    bool z_cols[col];
    
    memset(z_rows, false, row);
    memset(z_cols, false, col);

    // scan matrix to find zeros
    //
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == 0) {
                z_rows[i] = true;
                z_cols[j]= true;
            }
        }
    }

    // now start setting rows and cols to zero

    for (int i = 0; i < row; i++) {
       if (z_rows[i]) {
            setRowToZero((int*)m, row, col, i);
       }
    }

    for (int j = 0; j < col; j++) {
       if (z_cols[j]) {
           setColToZero((int*)m, row, j);
       }
    }

    cout << "After: " << endl;
   
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

