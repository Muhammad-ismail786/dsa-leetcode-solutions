# 10. Regular Expression Matching

**Difficulty:** Hard

**Topics:** String, Dynamic Programming, Recursion, Memoization

## Intuition

Initially, I thought of solving this problem using recursion by comparing the characters of the string `s` and pattern `p` from the end.

There are two special characters:

- `.` matches any single character.
- `*` matches zero or more occurrences of the preceding character.

Simple recursion can calculate the same subproblems multiple times, which can lead to Time Limit Exceeded.

To avoid repeated calculations, I used **Memoization (Dynamic Programming)** to store previously calculated results in a 2D DP array.

## Approach

1. First, calculate the lengths of the string `s` and pattern `p`.
2. Create a 2D DP array initialized with `-1`.
3. Use a recursive helper function `isMatchRec()` to solve the problem.
4. If the pattern becomes empty, return true only if the string is also empty.
5. If the last pattern character is `*`, handle two cases:
   - **Zero occurrences:** Ignore `*` and its preceding character by moving `m - 2`.
   - **One or more occurrences:** If the preceding character matches the current string character (or is `.`), move `n - 1` while keeping `m` unchanged.
6. If the last pattern character is a normal character or `.`, compare it with the last character of the string and move both backward.
7. Store the calculated result in the DP array to avoid repeated calculations.

## Complexity

- **Time complexity:** \(O(n \times m)\)
- **Space complexity:** \(O(n \times m)\)

Where:
- `n` = Length of string `s`.
- `m` = Length of pattern `p`.

## Code

```cpp
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
```
