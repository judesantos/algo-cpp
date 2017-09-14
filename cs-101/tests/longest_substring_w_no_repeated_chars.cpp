#include <iostream>
#include <cstring>

using namespace std;

int find_len_substring(char* s)
{
    int slen = strlen(s);
    int len = 0;
    
    for (int i = 0; i < slen; i++)
    {
        for (int j = i+1; j < slen; j++)
        {
            if (s[i] == s[j])
            {
                if (len < (j - i))
                {
                    len = j - i;
                }

                break;
            } 
        }                 
    }

    return len;
}
    
int main()
{
    char s[] =  "abcabcbb";

    int len = find_len_substring(s);

    cout << len << endl;

    return 0;
}
