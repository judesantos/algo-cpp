#include <iostream>
#include <cstring>

using namespace std;

void reverseString(char* p, int start, int end) 
{
    while (start < end)
    {
        char c = p[start];
        p[start] = p[end];
        p[end] = c;
        start++;
        end--;
    }
}

int main(int argc, char** argv) {

    char in[] = "Reverse    the words of this string.";

    int len =  strlen(in) - 1;

    // 1. Reverse entire string, resultant string is readable from left to right.

    reverseString(in, 0, len); 

    // 2. reverse each word

    int word_start = 0;
    int word_end = 0;

    char* p = in;
    
    while (*p != '\0') 
    {
        if (*p == ' ') 
        {
            reverseString(in, word_start, word_end - 1);
            word_start = word_end + 1;
        }

        p++;
        word_end++;
    }

    reverseString(in, word_start, word_end -1);

    cout << in << endl;
}
