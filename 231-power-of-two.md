# 231. Power of Two

## Intuition

We need to check whether the given number `n` is a power of two or not.

If `n` is less than or equal to 0, return `false`.

Otherwise, keep dividing `n` by 2 while it is divisible by 2. If the final value becomes 1, return `true`; otherwise, return `false`.

## Approach

1. First, check if `n <= 0`. If true, return `false`.
2. Use a `while` loop to check if `n % 2 == 0`.
3. If divisible by 2, divide `n` by 2.
4. Repeat until `n` is no longer divisible by 2.
5. Finally, return `true` if `n == 1`, otherwise return `false`.

## Complexity

- Time complexity: O(log n)
- Space complexity: O(1)

## Code

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n <= 0){
            return false;
        }

        while(n % 2 == 0){
            n = n / 2;
        }

        return n == 1;
    }
};
