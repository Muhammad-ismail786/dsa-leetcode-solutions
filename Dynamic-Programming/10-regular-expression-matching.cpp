
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return isMatchRec(s, p, n, m);
    }

    bool isMatchRec(const string& s, const string& p, int n, int m) {

        // Base case
        if (m == 0) {
            return n == 0;
        }

        // Already calculated?
        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        bool ans = false;

        // Handle '*'
        if (p[m - 1] == '*') {

            // Case 1: Zero occurrences
            bool zero = isMatchRec(s, p, n, m - 2);

            // Case 2: One or more occurrences
            bool oneOrMore = false;

            if (n > 0 &&
                (p[m - 2] == s[n - 1] || p[m - 2] == '.')) {

                oneOrMore = isMatchRec(s, p, n - 1, m);
            }

            ans = zero || oneOrMore;
        }

        // Handle normal character or '.'
        else {

            if (n > 0 &&
                (s[n - 1] == p[m - 1] || p[m - 1] == '.')) {

                ans = isMatchRec(s, p, n - 1, m - 1);
            }
        }

        // Save answer
        dp[n][m] = ans;

        return ans;
    }
};

int main() {

    Solution solution;

    string s, p;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Enter pattern: ";
    getline(cin, p);

    bool result = solution.isMatch(s, p);

    cout << boolalpha;
    cout << "Result: " << result << endl;

    return 0;
}
