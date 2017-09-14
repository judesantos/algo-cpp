#include <iostream>

using namespace std;

int main() {
    char s[] = "jsdfjdsfhracecarksdfjsdkfmalayalamcheck";

    const int len = sizeof(s)/sizeof(s[0]);
    
    cout << "len: " << len << endl;

    int longest = 0, loc = 0;

    for (int i = 0; i < len; i++) {
        int left = i;
        int right = i;
        int count = 0;

        while (left >  0) {
            if (s[left--] != s[right++]) 
                break;
            count++;
        }

        if (longest < count) {
            longest = count;
            loc = i;
        }
    }

    if (longest) {

        int start = loc - longest;
        int end = loc + longest;

        for (int x = start + 1; x < end; x++)
            cout << s[x];
        cout << endl;

        cout << "length: " << end - start - 1 << endl;

    }

    return 0;
}
    
