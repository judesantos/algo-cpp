#include <iostream>
#include <cstring>

using namespace std;

#define MAX_ASCII 127

int main() {

    char s1[] = "orchestra";
    char s2[] = "carthorse";
    
    if (strlen(s1) != strlen(s2)) {
        cout << "not an anagram" << endl;
    }

    int freq[MAX_ASCII] = {0};

    char* p = s1;

    while( *p != '\0')
    {
       char c = tolower(*p);
       freq[(int)c]++;
       p++;
    }

    p = s2;

    while (*p != '\0')
    {
        char c = tolower(*p);
        freq[(int)c]--;
        p++;
    }

    for (int x = 0; x < MAX_ASCII + 1; x++)
    {
        if (freq[x] >  0) 
        {
            cout << "Not an anagram" << endl;
            return 0;
        }
        continue;
    }

    cout << "Anagram" << endl;
}
