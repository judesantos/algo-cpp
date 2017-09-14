#include <iostream>
//#include <cstring>

using namespace std;

int  main() {

    char input[] = "jsdfjdsfhracecarksdfjsdkfmalayalamcheck";

    int location = 0;
    int maxsize = 0;

    int len = sizeof(input) / sizeof(char) - 1;
    
    for (int i = 0; i < len; i++) 
    {
        int left = i;
        int right = i;
        int count = 0;

        while (left > 0) 
        {
            if (input[left--] != input[right++]) {
                break;
            }

            count++;
        }

        if (count > maxsize)
        {
            maxsize = count;
            location = i;
        }
    }

    cout << maxsize << '@' << location << endl;

    int start = location - maxsize;
    int end = location + maxsize;

    for (int y = start + 1; y < end ;  y++)
        cout << input[y];

    cout << endl;

    return 0;
}
