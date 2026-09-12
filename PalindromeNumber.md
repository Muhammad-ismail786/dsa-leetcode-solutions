# Palindrome Number — Reverse and Compare

## Intuition

A palindrome number reads the same from left to right and right to left.

For example:
- `121` → palindrome
- `123` → not a palindrome

To solve this, we save the original number, reverse the digits of `x`, and then compare the reversed number with the original number.

## Approach

1. If `x` is negative, return `false`.
2. Store the original value of `x` in `original`.
3. Create a `reverse` variable and initialize it with `0`.
4. Use a `while` loop to reverse the number:
   - `x % 10` gives the last digit.
   - Add this digit to `reverse`.
   - `x / 10` removes the last digit from `x`.
5. Compare `original` with `reverse`.
6. If they are equal, return `true`; otherwise, return `false`.

## Complexity

- Time complexity: `O(log x)`
- Space complexity: `O(1)`

## Code

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int original = x;
        long long reverse = 0;

        while (x > 0) {
            int lastDigit = x % 10;
            reverse = reverse * 10 + lastDigit;
            x = x / 10;
        }

        if (original == reverse) {
            return true;
        }
        else {
            return false;
        }
    }
};
