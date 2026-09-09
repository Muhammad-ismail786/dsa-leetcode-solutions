# Longest Common Prefix

## Intuition

The first thought was to treat the first string as a base and compare each
character with the same position in every other string.

## Approach

Loop through each character of the first string...

## Complexity

- Time Complexity: O(n × m)
- Space Complexity: O(1)

## Code

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        for (int i = 0; i < strs[0].size(); i++) {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != currentChar) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
