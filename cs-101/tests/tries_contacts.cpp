#include <iostream>
#include <map>
#include <string>
#include <math.h>

#define null 0

using namespace std;

int main() {

    int n;

    cin >> n;

    // limit 1 < n < 10^5
    if (n < 1 || n > pow(10, 5))
        return -1;

    string op;
    string contact;
    // use set to maintain unique entries
    map<string, int> db;

    for(int a0 = 0; a0 < n; a0++) {

        // accept commands in sequence
        cin >> op >> contact;

        /*
         *validate inputs
         */

        // valid commands only
        if (op != "find" && op != "add")
            return 0;
        // limits
        if (contact.size() < 1 || contact.size() > 21)
            return 0;

        /*
         * process command
         */

        // add contact in db

        map<string, int>::iterator it;

        if (op == "add") {

          // create a hashmap of key=substr, val=count of
          // all possible substr for each contact.
          // increment count as we find similar words with same subst.

          for (int i = 1; i < contact.size(); ++i) {

              string sub = contact.substr(0, i);
              it = db.find(sub);

              if (it == db.end())
                  db[sub] = 1;
              else
                  db[sub] += 1;
          }

        } else if (op == "find") {

            // search substr
            cout << db[contact] << endl;
        }
    }

    return 0;
}
