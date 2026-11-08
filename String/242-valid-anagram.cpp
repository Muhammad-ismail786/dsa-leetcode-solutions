
#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length()) {
        return false;
    }

    int count[26] = {0};

    for (char ch : s) {
        count[ch - 'a']++;
    }

    for (char ch : t) {
        count[ch - 'a']--;

        if (count[ch - 'a'] < 0) {
            return false;
        }
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "Output: true" << endl;
    }
    else {
        cout << "Output: false" << endl;
    }

    return 0;
}
