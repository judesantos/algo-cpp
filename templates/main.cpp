#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Stack<string> s;
    
    string i = "first";
    string j = "second";

    s.push(i);
    s.push(j);

    int size = s.size();
    
    for (int x = 1; x <= size; x++)
    {
        string o = s.pop();
        cout << o << endl;
    }
    
    return 0;
}

