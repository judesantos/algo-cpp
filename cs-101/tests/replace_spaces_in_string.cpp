#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

int  main() {

    const int BUFF_LEN = 100; 
    char buff[100] = {0}; 
    
    const char* str = "Mr. John Smith";
    int str_len = strlen(str);

    memcpy(buff, str, str_len);

    cout << buff << endl;

    char* p = (char*) str;
    int nspaces = 0;

    // count spaces

    while (*p++ != '\0') {
        if (*p == ' ') {
            nspaces++;
        }
    }

    int index = str_len + (nspaces * 2);
     
    for (int i = str_len-1; i >= 0; i--) {
        if (buff[i] == ' ') {
            buff[index-1] = '0';
            buff[index-2] = '2';
            buff[index-3] = '%';
           
            index -= 3;
        } else {
            buff[index -1] = buff[i];
            index--;
        }
    }

    cout << "new string: " << buff << endl;
    return 0;
}
