#include <cstdio>
#include <math.h>

int main() {
    
    int t = 255;
    int len = (sizeof(t)) * 8;
    
    printf("bit length: %d\n", len);

    int count = 0;

    for (int x = 0; x < len; x++)
    {
        int y =(int)pow(2, x);
        printf("--- bit pos: %d\n", x);
        printf("--- bit pow: %d\n", y);
        
        if (t & y) {
            printf("--- count: %d\n", count + 1);
            count++;
        }
    }

    printf("num bits set: %d\n", count);
}
