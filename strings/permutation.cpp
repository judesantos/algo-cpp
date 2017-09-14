#include <iostream>
#include <cstring>

using namespace std;

int main() {

    const char* str = "abc";

    int len = strlen(str);

    for (int i = 0; i < len; i++) 
    {
        cout << str[i];

        for (int j = 0; j < len; j++)
        {
            if (i != j)
                cout << str[j];
        }
        cout << endl;
    }
}

