#include <cstdio>

int main() {

    int x = 240;

    // start from left.
    
    int len = 8 * sizeof(int);

    printf("len: %d\n", len);
    
    int start = -1, count = 0, last_count = 0, last_start = 0;

    for (int i = len-1; i >= 0 ; i--)
    {
        if (x & (1 << i)) 
        {
            if (start ==  -1)
                start = i;
            count++;
        } else {
           if (count > last_count) {
               last_count = count;
               last_start = start;
           }
           start = -1;
           count = 0;
        }
    } 

    printf("start: %d, count: %d", last_start, last_count);

    return 0;
}
