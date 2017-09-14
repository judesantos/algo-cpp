#include <iostream>

using namespace std;


int main(int args, char* argv[]) {

    char* s = argv[1];//"ewraA";
    int checker = 0;

    int i = 0;

    while (s[i] != 0) { 

        int val = s[i++];
        if (val == 0)
            break;

        cout << "char: " << (char)val << endl;
        cout << "val: " << val << endl;

        int imd = (1 << val);

        cout << "ascii: " << imd << endl;

        if (checker & imd) {
            cout << "string has duplicating chars" << endl;
            return -1;
        } else {
            checker |= (1 << val);
        }
    }
        //if (char_set[i]) {
        //    cout << "string has duplicating chars" << endl;
        //    return -1;
        //}
        //else 
        //{
        //    char_set[i] = argv[i];
        //}

        cout << "string is unique" << endl;
        return 0;
}
