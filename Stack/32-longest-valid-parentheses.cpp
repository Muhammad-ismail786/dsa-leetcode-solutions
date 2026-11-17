
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
            }

            if (st.empty()) {
                st.push(i);
            }
            else {
                ans = max(ans, i - st.top());
            }
        }

        return ans;
    }
};

int main() {

    Solution solution;

    string s;

    cout << "Enter parentheses string: ";
    getline(cin, s);

    int result = solution.longestValidParentheses(s);

    cout << "Longest Valid Parentheses Length: " << result << endl;

    return 0;
}
