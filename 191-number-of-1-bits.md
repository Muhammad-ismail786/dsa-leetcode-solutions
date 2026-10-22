# 191. Number of 1 Bits

## Intuition

We need to count the number of `1` bits in the binary representation of an integer `n`.

We check the last bit using the bitwise AND operator (`&`). If the bit is `1`, we increase the counter. Then, we shift the number one position to the right to check the next bit.

## Approach

1. Initialize `count = 0` because no bits have been counted yet.
2. Run a `while` loop while `n > 0`.
3. Use `n & 1` to check whether the last bit is `1`.
4. If it is `1`, increment `count`.
5. Use `n = n >> 1` to shift the bits one position to the right.
6. Return `count` after the loop finishes.

## Complexity

- **Time Complexity:** `O(log n)` — We process the binary bits one by one.
- **Space Complexity:** `O(1)` — We use a constant amount of extra space.

## Code

```cpp
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n > 0) {
            if (n & 1) {
                count++;
            }
            n = n >> 1;
        }

        return count;
    }
};
```
