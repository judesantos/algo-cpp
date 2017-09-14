#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char* p = "this is a test string";

    int spacecount = 0;
    int length = strlen(str);
    
    for ( int i = 0; i < length; i++ ) {
        if ( str[i] == ' ' )
            spacecount++;
    }

    int new_size = 2 * spacecount + length;
    char * str = new char[strlen(p)+1];
    memcpy(str, p, 

    for ( int i = length - 1; i >= 0; i-- ) {
        if ( str[i] == ' ' ) {
            str[new_size-1] = '0';
            str[new_size-2] = '2';
            str[new_size-3] = '%';
            new_size = new_size - 3;
        }
        else {
            str[new_size-1] = str[i];
            new_size = new_size - 1;
        }
    }

    delete [] str;

    cout << str << endl;
}
