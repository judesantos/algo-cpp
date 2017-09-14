#include <cstdio>
#include <cstring>

int toupper(int c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;

    return c;
}

int tolower(int c) {
    if (c >= 'A' && c <= 'Z')
        c = c + 32;

    return c;
}

void lower_upper_case_string_combination(char* s, int start, int end) {

    if (start == end) {
        printf("%s\n", s);
        return;
    }

    s[start] = toupper(s[start]);
    lower_upper_case_string_combination(s, start+1, end);

    s[start] = tolower(s[start]);
    lower_upper_case_string_combination(s, start+1, end);
}

int main() {
    
    char s[] = "eAdG";

    lower_upper_case_string_combination(s, 0, strlen(s));

    
}
