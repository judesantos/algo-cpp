#include <cstdio>


int main() {

    int x = 5, i =0;

    while(x) {

        printf("and op: %d\n", x & (x-1));
        if (x & (x-1)) {
            i++;
        }
        x--;
    }

    printf("i: %d\n", i);
}
