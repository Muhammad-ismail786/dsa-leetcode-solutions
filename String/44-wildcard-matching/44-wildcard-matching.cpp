
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        int i = 0;
        int j = 0;

        int star = -1;
        int match = 0;

        while (i < s.length()) {

            // Case 1: Characters match or '?' found
            if (j < p.length() &&
                (s[i] == p[j] || p[j] == '?')) {

                i++;
                j++;
            }

            // Case 2: '*' found
            else if (j < p.length() && p[j] == '*') {

                star = j;
                match = i;
                j++;
            }

            // Case 3: Previous '*' exists
            else if (star != -1) {

                j = star + 1;
                match++;
                i = match;
            }

            // Case 4: No match possible
            else {

                return false;
            }
        }

        // Ignore remaining '*' characters
        while (j < p.length() && p[j] == '*') {
            j++;
        }

        return j == p.length();
    }
};

int main() {

    string s, p;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Enter pattern: ";
    getline(cin, p);

    Solution obj;

    bool result = obj.isMatch(s, p);

    cout << "Output: " << boolalpha << result << endl;

    return 0;
}
