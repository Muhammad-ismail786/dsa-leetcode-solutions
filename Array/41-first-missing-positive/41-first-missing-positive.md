# 41. First Missing Positive

## Intuition

We need to find the smallest positive integer that is missing from the given array.

We can solve this problem using the Cyclic Sort technique.

The idea is to place every valid positive number at its correct index.

For example:

- Number `1` should be at index `0`.
- Number `2` should be at index `1`.
- Number `3` should be at index `2`.
- Number `4` should be at index `3`.

After placing numbers at their correct positions, we traverse the array again.

If `nums[i]` is not equal to `i + 1`, then `i + 1` is the first missing positive integer.

## Approach

1. Get the size of the array and store it in `n`.
2. Traverse the array using a `for` loop.
3. Use a `while` loop to place each valid positive number at its correct index.
4. Check three conditions:
   - The number must be greater than or equal to `1`.
   - The number must be less than or equal to `n`.
   - The correct position must not already contain the same number.
5. Swap the current number with the number at its correct position.
6. Traverse the array again.
7. If `nums[i] != i + 1`, return `i + 1` because it is the smallest missing positive integer.
8. If all positions contain their correct numbers, return `n + 1`.

## Complexity

- Time complexity: $$O(n)$$

  Each valid number is moved to its correct position at most once. We traverse the array twice, so the overall time complexity is O(n).

- Space complexity: $$O(1)$$

  We rearrange the original array in place and use only a constant amount of extra space.

## Code

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            while (nums[i] >= 1 &&
                   nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {

                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {

            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
```
