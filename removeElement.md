# LeetCode 27: Remove Element

## Intuition

We need to remove all occurrences of `val` from the array.

Instead of creating a new array, we modify the original array in-place.

We use two indexes:

* `i` → traverses the array.
* `k` → keeps track of the position where the next valid element should be placed.

If `nums[i]` is not equal to `val`, we keep that element by placing it at `nums[k]`.

## Approach

1. Initialize `k = 0`.
2. Loop through the array using `i`.
3. Check if `nums[i]` is not equal to `val`.
4. If `nums[i] != val`, place `nums[i]` at `nums[k]`.
5. Increment `k`.
6. Continue until all elements have been checked.
7. Return `k`.

## Example

Input:

```text
nums = [3,2,2,3]
val = 3
```

We remove all `3`s.

The first two elements become:

```text
[2,2]
```

So:

```text
k = 2
```

## Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(1)**

## Code

```cpp
// LeetCode 27: Remove Element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```
