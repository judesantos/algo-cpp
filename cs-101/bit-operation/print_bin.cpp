#include <iostream>
#include <string>

using namespace std;

/**
 * given double value between n > 0 && n < 1.
 * show the equivalent binary representation.
 */

string print_binary(float n) {
    if (n <= 0 && n >=1)
        return "Error";

    string bin;
    bin += ".";

    while (n > 0) {
        // set limit to decimal pos
        if (bin.size() > 32) {
            return "Error";
        }

        float r = n * 2;

        if (r >= 1) {
            bin += "1";
            n = r - 1;
        } else {
            bin += "0";
            n = r;
        }
    }

    return bin;
}

int main() {


    string bin = print_binary(0.72);

    cout << "bin: " << bin << endl;
    
    return 0;
}

