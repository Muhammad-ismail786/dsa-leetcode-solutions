
# 4. Median of Two Sorted Arrays

**LeetCode Problem:** 4

**Difficulty:** Hard

**Topic:** Array, Binary Search, Divide and Conquer

## Intuition

We are given two sorted arrays, and we need to find their median without merging them.

Instead of merging both arrays, we use Binary Search to divide the smaller array into two parts.

We also divide the second array so that:

- The left half contains half of the total elements.
- The right half contains the remaining elements.
- Every element on the left side is less than or equal to every element on the right side.

We perform Binary Search on the smaller array because it reduces the search space and improves efficiency.

## Approach

1. First, check which array is smaller. If `nums1` is larger than `nums2`, swap the arrays by calling the function recursively.

2. Initialize the binary search boundaries:
   - `low = 0`
   - `high = m`

3. Calculate the partition positions:
   - `cut1` represents the number of elements taken from the first array.
   - `cut2` represents the number of elements taken from the second array.

4. Find the four boundary values:
   - `l1`: Last element on the left side of the first array.
   - `r1`: First element on the right side of the first array.
   - `l2`: Last element on the left side of the second array.
   - `r2`: First element on the right side of the second array.

5. Use `INT_MIN` and `INT_MAX` to handle empty partitions safely.

6. Check whether the partition is correct:
   - `l1 <= r2`
   - `l2 <= r1`

7. If the partition is correct:
   - If the total number of elements is even, return the average of the maximum left value and minimum right value.
   - If the total number of elements is odd, return the maximum left value.

8. If `l1 > r2`, move the binary search to the left by updating `high = cut1 - 1`.

9. Otherwise, move the binary search to the right by updating `low = cut1 + 1`.

## Complexity

- Time complexity: `O(log(min(m, n)))`

  Binary Search is performed on the smaller array.

- Space complexity: `O(1)`

  Only a constant number of variables are used.

## Code

```cpp
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {

                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                return max(l1, l2);
            }

            else if (l1 > r2) {
                high = cut1 - 1;
            }

            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
```
