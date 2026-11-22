
# 44. Wildcard Matching

**Difficulty:** Hard

**Language:** C++

**Approach:** Greedy Algorithm

## Intuition

We need to check whether the given pattern `p` matches the entire string `s`.

There are two special characters:

- `?` matches any single character.
- `*` matches any sequence of characters, including an empty sequence.

We use a Greedy Approach to solve this problem.

We keep track of the last `*` position and use it to match additional characters whenever a mismatch occurs.

## Approach

1. Initialize two pointers `i` and `j` to traverse strings `s` and `p`.
2. Initialize `star = -1` to store the last position of `*`.
3. Initialize `match = 0` to store the position in string `s` where `*` starts matching.
4. If characters match or the pattern contains `?`, increment both pointers.
5. If the pattern contains `*`, save its position in `star` and the current string position in `match`.
6. If a mismatch occurs and a previous `*` exists, let `*` match one additional character and continue checking.
7. If no previous `*` exists, return `false`.
8. After processing the string, skip any remaining `*` characters in the pattern.
9. Return `true` if the entire pattern has been matched; otherwise, return `false`.

## Complexity

- **Time Complexity:** O(n + m) — Each pointer moves forward through its string, with greedy backtracking handled in linear amortized time.
- **Space Complexity:** O(1) — Only a constant number of variables are used.

## Code

\`\`\`cpp
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
\`\`\`
