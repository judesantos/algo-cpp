#include <iostream>

using namespace std;

bool isRotation(string& s1, string& s2) {
    
    if (s1.size() != s2.size())
        return false;

    string s1s1 = s1 + s1;
    
    cout << "s1s1: " << s1s1 << endl;

    size_t pos = s1s1.find(s2);

    if (pos == string::npos)
        cout << "de malas" << endl;

    return pos != string::npos;
}
int main() {

    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    cout << "is substring: " << (isRotation(s1, s2) ? "true" : "false") << endl;

    return 0;
}
