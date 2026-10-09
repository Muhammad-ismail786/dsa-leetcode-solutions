# 136. Single Number

## Intuition

The first thought is to use the XOR (`^`) operator to find the number that appears only once in the array.

XOR has two important properties:

* A number XORed with itself gives `0`. For example, `2 ^ 2 = 0`.
* A number XORed with `0` remains unchanged. For example, `0 ^ 5 = 5`.

Since every number appears twice except one number, the duplicate numbers cancel each other out, leaving the single number as the final result.

## Approach

1. Initialize `result = 0`.
2. Traverse the array using a `for` loop.
3. XOR each array element with `result` and store the answer back in `result`.
4. After processing all elements, return `result`. The remaining value is the number that appears only once.

## Complexity

* **Time complexity:** \(O(n)\) — We traverse the array once.
* **Space complexity:** \(O(1)\) — We use only one extra variable, `result`.

## Code

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }

        return result;
    }
};
```
