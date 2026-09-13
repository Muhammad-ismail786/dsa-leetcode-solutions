# Valid Parentheses using Stack

## Intuition

We need to check whether every opening bracket has the correct closing bracket.

A stack is useful because brackets must be closed in the reverse order in which they were opened.

For example:

`({[]})`

The last opening bracket is `[` so it must be closed first with `]`.

Therefore:

* Opening brackets `(`, `{`, `[` are pushed into the stack.
* Closing brackets `)`, `}`, `]` are checked against the top of the stack.
* If the bracket matches, it is removed using `pop()`.
* If it does not match, the string is invalid.
* At the end, the stack must be empty.

## Approach

1. Create an empty stack.
2. Traverse the string from left to right.
3. If the character is an opening bracket, push it into the stack.
4. If the character is a closing bracket:

   * Check if the stack is empty.
   * Check whether the top bracket matches.
   * If it matches, pop it.
   * Otherwise, return `false`.
5. After processing the complete string, return `st.empty()`.

If the stack is empty, all brackets were correctly matched.

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

## Code

```cpp
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            // Opening brackets
            if(s[i] == '(') {
                st.push(s[i]);
            }

            if(s[i] == '{') {
                st.push(s[i]);
            }

            if(s[i] == '[') {
                st.push(s[i]);
            }

            // Closing )
            if(s[i] == ')') {

                if(st.empty()) {
                    return false;
                }

                if(st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }

            // Closing }
            if(s[i] == '}') {

                if(st.empty()) {
                    return false;
                }

                if(st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }

            // Closing ]
            if(s[i] == ']') {

                if(st.empty()) {
                    return false;
                }

                if(st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
```
