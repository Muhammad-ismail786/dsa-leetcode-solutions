
# LeetCode 32: Longest Valid Parentheses

## # Intuition

We are given a string containing only opening `(` and closing `)` parentheses.

We need to find the length of the longest valid parentheses substring.

Examples:
- `()` is valid.
- `(())` is valid.
- `()()` is valid.
- `((` is invalid.
- `)(` is invalid.

We can solve this problem using a Stack. Instead of storing parentheses, we store their indexes in the stack.

## # Approach

1. Create a stack to store indexes of parentheses.
2. Push `-1` into the stack as the starting boundary.
3. Initialize an answer variable with `0`.
4. Traverse the string using a loop.
5. If the current character is `(`, push its index into the stack.
6. Otherwise, pop the top index from the stack.
7. If the stack becomes empty, push the current index as a new boundary.
8. Otherwise, calculate the valid substring length using `i - st.top()`.
9. Update the maximum answer using `max()`.
10. Return the final answer.

## # Complexity

- Time complexity: `O(n)`

  We traverse the string only once.

- Space complexity: `O(n)`

  In the worst case, the stack can store up to `n` indexes.

## # Code

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
            }

            if (st.empty()) {
                st.push(i);
            } else {
                ans = max(ans, i - st.top());
            }
        }

        return ans;
    }
};
```
