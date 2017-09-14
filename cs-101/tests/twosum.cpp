#include <iostream>
#include <cstdlib>

using namespace std;

// given an array of integers, find the indices of the 2 numbers that is the sum of the input value; 

int main(int argc, char* argv[]) 
{
    int input = atoi(argv[1]);

    cout << input << endl;

    int arr[] = {2, 11, 7, 15};
    int len = sizeof(arr);
   
    bool found = false;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++) 
        {
           if (j != i) 
           {
                if (input == (arr[i] + arr[j]))
                {
                    cout << "indices: " << i << "=" << arr[i] << ", " << j << "=" << arr[j] << endl;    
                    found = true;
                    break;
                }
           }
                
           if (found) break;
        }
        if (found) break;
    }

}
