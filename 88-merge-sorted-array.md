# 88. Merge Sorted Array

**Difficulty:** Easy
**Topic:** Array, Two Pointers

## Problem

Given two sorted integer arrays `nums1` and `nums2`, merge them into one sorted array.

The first `m` elements of `nums1` contain actual values, while the remaining `n` positions are empty spaces represented by `0`.

The final sorted array must be stored directly inside `nums1`.

## Intuition

Both arrays are already sorted.

Instead of starting from the beginning, we start from the **end** of both arrays.

We compare the largest remaining elements and put the larger element at the last available position in `nums1`.

This is useful because `nums1` already has extra space at the end, so we can fill those positions without overwriting the elements we still need.

## Approach

1. Set `i` to the last actual element of `nums1`.
2. Set `j` to the last element of `nums2`.
3. Set `k` to the last position of `nums1`.
4. Compare `nums1[i]` and `nums2[j]`.
5. Put the larger value at `nums1[k]`.
6. Move the pointer of the array from which we took the value.
7. Move `k` backward.
8. Continue until either `nums1` or `nums2` has no elements left.
9. If elements remain in `nums2`, copy them into `nums1`.

## Example

```text
nums1 = [1, 2, 3, 0, 0, 0]
m = 3

nums2 = [2, 5, 6]
n = 3
```

Start from the end:

```text
3 vs 6 → place 6
3 vs 5 → place 5
3 vs 2 → place 3
2 vs 2 → place 2
1 vs 2 → place 2
```

Final result:

```text
[1, 2, 2, 3, 5, 6]
```

## Complexity

* **Time Complexity:** `O(m + n)`
* **Space Complexity:** `O(1)`

## Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
```

## Key Learning

The main idea is to **merge from right to left**.

Because `nums1` has extra empty positions at the end, placing the largest elements there prevents us from overwriting the values that still need to be compared.
