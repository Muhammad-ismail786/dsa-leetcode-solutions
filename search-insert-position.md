# Intuition

The array is sorted in ascending order, so we can use **Binary Search** instead of checking every element one by one.

We keep two pointers:

* `left` → starting index of the search range
* `right` → ending index of the search range
* `mid` → middle index of the current search range

If `target` is equal to `nums[mid]`, we found the target and return `mid`.

If `target` is greater than `nums[mid]`, we search in the right half.

If `target` is smaller than `nums[mid]`, we search in the left half.

If the target is not found, `left` will point to the correct position where the target should be inserted, so we return `left`.

# Approach

1. Set `left = 0`.
2. Set `right = nums.size() - 1`.
3. Run Binary Search while `left <= right`.
4. Calculate the middle index:
   `mid = (left + right) / 2`
5. Compare `target` with `nums[mid]`:

   * If equal → return `mid`.
   * If `target > nums[mid]` → move `left` to `mid + 1`.
   * Otherwise → move `right` to `mid - 1`.
6. If the loop ends, the target was not found.
7. Return `left`, because it represents the correct insertion position.

# Complexity

* Time complexity: **O(log n)**
* Space complexity: **O(1)**

# Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = (left + right) / 2;

            if(target == nums[mid]) {
                return mid;
            }
            else if(target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};
```
