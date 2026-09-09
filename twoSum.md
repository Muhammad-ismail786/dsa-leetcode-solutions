# LeetCode 1: Two Sum

## Intuition

We need to find two numbers in the array whose sum equals the target.

Instead of checking every possible pair, we can use a hash map to store numbers
we have already seen along with their indexes.

For each number, we calculate the required value:

required = target - current

If the required value already exists in the hash map, we have found the answer.

## Approach

1. Create an `unordered_map` to store each number and its index.
2. Loop through the array.
3. For each number, calculate:
   
   `required = target - current`
   
4. Check if `required` already exists in the map.
5. If it exists, return the index of `required` and the current index.
6. Otherwise, store the current number and its index in the map.
7. If no pair is found, return an empty vector.

## Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

## Code

```cpp
// LeetCode 1: Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int required = target - current;

            if (map.find(required) != map.end()) {
                return {map[required], i};
            }

            map[current] = i;
        }

        return {};
    }
};
