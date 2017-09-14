#include <iostream>
#include <algorithm>

using namespace std;

void swap(string& s, int idx1, int idx2) {
    char tmp = s[idx1];
    s[idx1] = s[idx2];
    s[idx2] = tmp;
}

void permute(string& s, int mid, int end) {
    
    static int count = 0;
    if (mid == end) {
        cout << ++count << " : " << s << endl;
    }
    else 
    {
        for (int i = mid; i <= end; i++) {
            swap(s, mid, i);
            permute(s, mid+1, end);
            swap(s, mid, i);
        }
    }
}

int main() 
{
    string s = "abc";

    cout << s << endl;

    permute(s, 0, s.size()-1);
}
