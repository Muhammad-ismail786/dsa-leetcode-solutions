# Length of Last Word – Reverse Traversal

## Intuition

Start checking the string from the end because we only need the **last word**.

First, skip any spaces at the end of the string. Then count the characters of the last word.

When we find a space after counting some characters, it means the last word has ended, so we stop and return the count.

## Approach

1. Initialize `count = 0`.
2. Start a loop from the last character of the string.
3. If the current character is a space, skip it using `continue`.
4. If the current character is not a space, increment `count`.
5. Check if the character before the current character is a space.
6. If it is a space, the last word is complete, so use `break`.
7. Return `count`.

## Complexity

* Time complexity: \(O(n)\)
* Space complexity: \(O(1)\)

## Code

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;

        for(int i = s.size() - 1; i >= 0; i--) {

            if(s[i] == ' ') {
                continue;
            }
            else {
                count++;

                if(i > 0 && s[i - 1] == ' ') {
                    break;
                }
            }
        }

        return count;
    }
};
```
