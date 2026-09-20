# Incrementing a Number Represented by Digits

## Intuition

The number is represented as an array of digits.

To add `1`, we start from the last digit because addition begins from the rightmost side.

* If the current digit is less than `9`, simply add `1` and return the result.
* If the current digit is `9`, it becomes `0`, and the carry moves to the previous digit.
* If all digits are `9`, all of them become `0`, so we add a new `1` at the beginning.

## Approach

1. Start traversing the array from the last digit.
2. Check if the current digit is `9`.
3. If it is `9`, change it to `0` and continue to the previous digit.
4. If it is not `9`, increment it by `1` and return the array.
5. If the loop finishes, it means all digits were `9`.
6. Insert `1` at the beginning of the array.
7. Return the final array.

## Example

### Input

```text
[1, 2, 9]
```

### Process

```text
9 → 0
2 → 3
```

### Output

```text
[1, 3, 0]
```

For an input like:

```text
[9, 9, 9]
```

all digits become `0`:

```text
[0, 0, 0]
```

Then we insert `1` at the beginning:

```text
[1, 0, 0, 0]
```

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` auxiliary space

The array is modified in place. In the case where all digits are `9`, the vector grows by one element.

## Code

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--) {

            if(digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

## Key Concept

**Array Traversal + Carry Handling**

The main idea is to process the digits from right to left and propagate the carry whenever a digit is `9`.
