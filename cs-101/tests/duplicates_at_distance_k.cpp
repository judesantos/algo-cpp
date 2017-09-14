#include <iostream>

using namespace std;

int main(int args, char* argv[])
{
    int k = args > 1 ? (int)argv[0][0] : -1;

    while (k <= 0)
    {
        cout << "enter a positive integer value between 1 and 10" << endl;
        cin >> k;
    }

    cout << " input value is: " << k << endl;

    int arr[] = {1, 2, 3, 4, 2, 6, 5, 6, 7, 8};

    int len = sizeof(arr) / sizeof(arr[0]);

    cout << " Len is: " << len << endl;

    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (arr[i] == arr[j]) {
                if ((j-i) > 0 && (j-i) <= k) {
                    cout << arr[i] << " duplicate distance is " << (j-i) << ", within range of " << k << endl;
                    return 0;
                }
            }
        }
    }
     
    cout << " no duplicate elements within " << k << endl;

    return -1;
}

