# 168. Excel Sheet Column Title

## Intuition

In Excel, column numbers are represented by letters instead of normal numbers.

For example:
- `1` → `"A"`
- `2` → `"B"`
- `26` → `"Z"`
- `27` → `"AA"`
- `28` → `"AB"`
- `701` → `"ZY"`

We need to convert a given integer `columnNumber` into its corresponding Excel column title.

The main idea is to use division and remainder with `26`, because the English alphabet contains 26 letters.

However, Excel column numbering starts from `1`, whereas remainder-based calculations work more conveniently with positions starting from `0`. Therefore, we subtract `1` from `columnNumber` before calculating the remainder.

The remainder tells us which letter to select, and integer division by `26` gives us the number to process for the next letter.

Since we calculate the letters from right to left, we reverse the final string to get the correct column title.

## Approach

1. Create an empty string `result` to store the letters of the column title.

2. Run a `while` loop as long as `columnNumber > 0`.

3. Subtract `1` from `columnNumber` to adjust Excel's 1-based numbering to 0-based numbering.

4. Calculate `remainder = columnNumber % 26` to find the position of the current letter, from `0` to `25`.

5. Convert the remainder into a character using `char('A' + remainder)`.
   - If `remainder = 0`, the character is `'A'`.
   - If `remainder = 1`, the character is `'B'`.
   - If `remainder = 25`, the character is `'Z'`.

6. Append the character to `result`.

7. Divide `columnNumber` by `26` using integer division to process the next letter.

8. Repeat until `columnNumber` becomes `0`.

9. Reverse `result` because the letters were collected from right to left.

10. Return `result` as the final Excel column title.

## Complexity

- **Time complexity:** \(O(\log_{26} n)\), where \(n\) is the given `columnNumber`. We divide the number by `26` in each iteration, so the number of iterations grows logarithmically with the input.

- **Space complexity:** \(O(\log_{26} n)\), for storing the resulting column title. The title contains a number of characters proportional to \(\log_{26} n\).

## Code

```cpp
class Solution {
public:
    string convertToTitle(int columnNumber) {

        string result;

        while (columnNumber > 0) {
            columnNumber--;

            int remainder = columnNumber % 26;

            result += char('A' + remainder);

            columnNumber = columnNumber / 26;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
```
