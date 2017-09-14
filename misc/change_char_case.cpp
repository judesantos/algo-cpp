#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void change_case(char s[])
{
    int x = 0;
    while(s[x] != '\0') 
    {
        if (s[x] >= 'a' && s[x] <= 'z')
            s[x] -= 32;
        else if (s[x] >= 'A' && s[x] <= 'Z') 
            s[x] += 32;
        x++;
    }
}

main() {
    
    char string[] = "This Is A StRinG";// = {0};
    
    //cin >> string;

    cout << string << endl;    
    
    change_case(string);

    cout << string << endl;

}
