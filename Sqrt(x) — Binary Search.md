# Sqrt(x) — Binary Search

## Intuition

We need to find the integer square root of `x`.

Instead of checking every number one by one, we use **Binary Search**.

For a number `mid`:

* If `mid * mid == x`, then `mid` is the exact square root.
* If `mid * mid > x`, `mid` is too large, so we search on the left side.
* If `mid * mid < x`, `mid` is too small, so we search on the right side.

At the end, `right` contains the largest integer whose square is less than or equal to `x`.

## Approach

1. Set `left = 0` and `right = x`.
2. Calculate the middle value:
   `mid = left + (right - left) / 2`.
3. Compare `mid * mid` with `x`.
4. If they are equal, return `mid`.
5. If `mid * mid` is greater than `x`, move `right` to `mid - 1`.
6. If `mid * mid` is smaller than `x`, move `left` to `mid + 1`.
7. Continue until `left > right`.
8. Return `right`, which is the largest valid integer square root.
9. Use `1LL` when multiplying `mid * mid` to prevent integer overflow.

## Complexity

* **Time complexity:** `O(log x)`
* **Space complexity:** `O(1)`

## Code

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (1LL * mid * mid == x)
            {
                return mid;
            }

            if (1LL * mid * mid > x)
            {
                right = mid - 1;
            }

            if (1LL * mid * mid < x)
            {
                left = mid + 1;
            }
        }

        return right;
    }
};
```
