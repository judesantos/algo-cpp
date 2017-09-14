#include <iostream>

using namespace std;

// check if inserting missing char in s2 will complete the edit
bool isEditInsert(string s1, string s2) {
    
    if (s1.size() < s2.size())
        return false;

    int idx1 = 0;
    int idx2 = 0;

    while(idx1 < s1.size() && idx2 < s2.size())
    {
        if (s1.at(idx1) != s2.at(idx2)) {
            if (idx1 != idx2)
                return false;
            idx1++;
        }
        else 
        {
            idx1++;
            idx2++;
        }
    }
    
    return true;
}

bool isEditReplace(string s1, string s2) {

    int found = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1.at(i) != s2.at(i)) {
            found++;
        }
    }

    return found == 1 ? true : false;;
}

bool one_edit_away(string s1, string s2) {

    if (s1.size() == s2.size())  {
        return isEditReplace(s1, s2);
    } else if (s1.size() - 1 == s2.size()) {
        return isEditInsert(s1, s2);
    } else if (s1.size() + 1 == s2.size()) {
        return isEditInsert(s2, s1);
    }

    return false;
}

int main() {

    if (one_edit_away("pale", "ple")) {
        cout << "edit insert is true" << endl;
    } else {
        cout << false << endl;
    }

    if (one_edit_away("pales", "pale")) {
        cout << "edit insert is true" << endl;
    } else {
        cout << false << endl;
    }
    
    if (one_edit_away("pale", "bale")) {
        cout << "edit replace is true" << endl;
    } else {
        cout << false << endl;
    }

    if (one_edit_away("pale", "bae")) {
        cout << "edit insert is true" << endl;
    } else {
        cout << false << endl;
    }

    return 0;
}
