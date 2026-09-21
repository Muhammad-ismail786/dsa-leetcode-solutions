# Add Binary Strings – Binary Addition with Carry

## Intuition

The idea is to add the two binary strings from right to left, just like normal binary addition.

Since the strings can have different lengths, we process each string only while its index is valid. A `carry` is maintained whenever the sum is `2` or `3`.

Instead of converting the binary strings into decimal numbers, we directly process their digits. This allows the solution to work efficiently even for very large binary strings.

## Approach

1. Start from the last digit of both strings using two pointers, `i` and `j`.
2. Initialize `carry` to `0` and create an empty `result` string.
3. Continue the loop while either string still has digits or a `carry` remains.
4. Get the current digit from `a` and `b`. If one string has no digits left, use `0`.
5. Calculate the sum of both digits and the current `carry`.
6. Use `sum % 2` to get the current binary digit.
7. Use `sum / 2` to calculate the new `carry`.
8. Move the pointers toward the left.
9. Since the digits are added from right to left, reverse the `result` before returning it.

## Complexity

* **Time Complexity:** `O(n)`

  Where `n` is the length of the longer binary string.

* **Space Complexity:** `O(n)`

  The result string requires space proportional to the length of the output.

## Code

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int digitA = 0;
            int digitB = 0;

            if (i >= 0) {
                digitA = a[i] - '0';
                i--;
            }

            if (j >= 0) {
                digitB = b[j] - '0';
                j--;
            }

            int sum = digitA + digitB + carry;

            result += (sum % 2) + '0';

            carry = sum / 2;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
```
