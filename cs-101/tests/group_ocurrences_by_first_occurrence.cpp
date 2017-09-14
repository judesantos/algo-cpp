#include <iostream>

using namespace std;

int main()
{
    int arr[] = {5, 3, 5, 1, 3, 3};

    const int len = sizeof(arr) / sizeof(arr[0]);

    bool occurred[len] = {false};

    for (int i = 0; i < len; i++) {
        if (!occurred[i]) {
            occurred[i] = true;
            cout << arr[i] << " " << endl;
            
            for (int j= i+1; j < len; j++) {
                if (arr[i] == arr[j]) {
                    cout << arr[j] << " " << endl;
                    occurred[j] = true;
                }
            }
        }
    }

    return 0;
}
