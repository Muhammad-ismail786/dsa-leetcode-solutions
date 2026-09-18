# Remove Duplicates from Sorted Array – Two Pointer In-Place

## Intuition

The array is already sorted, so duplicate elements are always next to each other.

We can compare the current element with the previous element.

* If both are the same, it is a duplicate, so we skip it.
* If they are different, it is a unique element, so we place it at the next available position.

We use `k` to keep track of the position where the next unique element should be placed.

## Approach

1. Start `k` from `1` because the first element is always unique.
2. Start the loop from index `1`.
3. Compare `nums[i]` with `nums[i - 1]`.
4. If they are different:

   * Place `nums[i]` at `nums[k]`.
   * Increment `k`.
5. If they are the same, skip the duplicate.
6. Return `k`, which represents the number of unique elements.

### Example

```text
nums = [1, 1, 2]

k = 1

i = 1
nums[1] = 1
nums[0] = 1

1 == 1 → Duplicate → Skip

i = 2
nums[2] = 2
nums[1] = 1

2 != 1 → Unique

nums[k] = nums[i]
nums[1] = nums[2]

Array becomes:
[1, 2, 2]

k = 2
```

The first `k` elements are:

```text
[1, 2]
```

So the answer is:

```text
k = 2
```

## Complexity

* Time complexity: **O(n)**
* Space complexity: **O(1)**

## Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```
