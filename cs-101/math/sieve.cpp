#include <iostream>
#include <cstdlib>
#include <memory.h>

using namespace std;

int main(int args, char* argv[])
{
    if (args <= 1)
        return -1;

    int num = atoi(argv[1]);
    bool primes[num+1];

    memset(primes, true, num+1);



    return 0;
}
