# Intuition

Each Excel column title represents a number. The letters range from A = 1 to Z = 26.

For example:
- A = 1
- Z = 26
- AA = 27
- AB = 28

We can treat the column title like a base-26 number, where each letter has a value from 1 to 26.

For every letter, we multiply the current result by 26 and add the value of that letter.

# Approach

1. Initialize `result = 0`.
2. Traverse each character in `columnTitle` using a for loop.
3. Multiply `result` by 26 to make room for the next letter.
4. Calculate the current letter's value using `letter - 'A' + 1`.
5. Add the letter's value to `result`.
6. Return the final result.

For example, if `columnTitle = "AB"`:

- Start with `result = 0`.
- For A: `result = 0 * 26 + 1 = 1`.
- For B: `result = 1 * 26 + 2 = 28`.

Therefore, the answer is `28`.

# Complexity

- Time complexity: `O(n)` — We traverse each character once, where `n` is the length of the column title.
- Space complexity: `O(1)` — We use only a constant amount of extra space.

# Code

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char letter : columnTitle) {
            result = result * 26;

            int letterValue = letter - 'A' + 1;

            result = result + letterValue;
        }

        return result;
    }
};
```
