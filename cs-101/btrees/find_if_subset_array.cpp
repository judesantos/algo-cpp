#include <iostream>

using namespace std;

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    bool subset = false;
    
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j]) 
            {
                subset = true;
                break;
            }
        }

        if (!subset)
            break;
    }

    if (subset)
        cout << "arr2 is a subset of arr1" << endl;
    else
        cout << "arr2 is not a subset of arr1" << endl;
        
    return 0;
}

