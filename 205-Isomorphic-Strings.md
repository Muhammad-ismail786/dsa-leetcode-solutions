# 205. Isomorphic Strings

## Intuition
The idea is to check whether each character in string `s` consistently maps to the same character in string `t`, and vice versa. Both strings must follow the same character pattern.

## Approach
1. If the lengths of `s` and `t` are different, return `false`.
2. Create two arrays, `mapS` and `mapT`, of size 256, initialized with `0`.
3. Traverse both strings using index `i`.
4. If `mapS[s[i]] != mapT[t[i]]`, return `false` because the character patterns do not match.
5. Update `mapS[s[i]]` and `mapT[t[i]]` with `i + 1`.
6. If all characters match the pattern, return `true`.

## Complexity
- Time complexity: `O(n)`
- Space complexity: `O(1)`

## Code
See [205-Isomorphic-Strings.cpp](205-Isomorphic-Strings.cpp).
