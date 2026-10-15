# 169. Majority Element

## Intuition

We need to find the element that appears more than half the time in the array. This element is called the majority element.

We can use the Boyer-Moore Voting Algorithm to find a possible majority element efficiently.

We maintain two variables:
- `candidate`: Stores the current possible majority element.
- `count`: Keeps track of the candidate's votes.

When the count becomes zero, we select the current element as the new candidate. If the current element matches the candidate, we increase the count. Otherwise, we decrease the count.

After finding a candidate, we traverse the array again to count its actual occurrences and verify whether it appears more than half the time.

## Approach

1. Initialize `candidate = 0` and `count = 0`.
2. Traverse the array:
   - If `count == 0`, select the current element as the candidate and set `count = 1`.
   - If the current element equals the candidate, increment `count`.
   - Otherwise, decrement `count`.
3. Reset `count = 0`.
4. Traverse the array again and count how many times the candidate appears.
5. If its frequency is greater than `nums.size() / 2`, return the candidate.
6. Otherwise, return `-1`.

## Complexity

- **Time Complexity:** `O(n)` — We traverse the array twice.
- **Space Complexity:** `O(1)` — We use only a constant number of extra variables.

## Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        count = 0;

        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return candidate;
        }

        return -1;
    }
};
```
