#include <iostream>

using namespace std;

#define MAX_STRING 125;

// case insensitive find permutation of string a in string b.

void sort(string& s) {

    bool swapped = true;

    while (swapped) {
        
        swapped = false;

        for (int i = 0; i < s.size(); i++) 
        {
            for (int j = i+1; j < s.size(); j++)
            {
               if (s[i] > s[j]) 
               {
                   int tmp = (int)s[i];
                   s[i] = s[j];
                   s[j] = tmp;

                   swapped = true;
               }
            }
        }
    }
}

int main() {

    string s = "abbc";
    string b = "cbabadcbbabbcbabaabccbabc";

    sort(s);
    
    cout << "s sorted: " << s << endl;

    for (int i = 0; i < b.size(); i++) {

        string w = b.substr(i, s.size());

        sort(w);
    
        if (w == s) {
            cout << i << ".) " << b.substr(i, s.size()) << endl;
        }
    }

    return 0;
}
