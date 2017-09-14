#include <cstdio>

int main() 
{
    int x[3];
    int i = 0;
    
    printf("%d %d\n", i, x[i]);
     printf("%d\n", x[0]);
     printf("%d\n", x[1]);
     printf("%d\n\n", x[2]);

    x[i] = x[i++];

     printf("%d %d\n", i, x[i]);
     printf("%d\n", x[0]);
     printf("%d\n", x[1]);
     printf("%d\n", x[2]);
}
