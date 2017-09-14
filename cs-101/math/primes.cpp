#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    
    if (n%2==0)
        return true;

    int m = sqrt(n);

    for (int i=3; i <= m; i+=2)
    {
        if (n%i==0)
            return false;
    }
        
    return true;
}

int main(int args, char* argv[])
{
    if (args <= 1)
    {
        cout << "Enter a number to find out if a prime number." << endl;
        return -1;
    }

    int num = atoi(argv[1]);
    int m = sqrt(num);

    cout << "is " << num << " prime? " << (is_prime(num) ? " yes!" : " no. ") << endl;

    return 0;
}
