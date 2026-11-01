# 219. Contains Duplicate II

**Difficulty:** Easy
**Topics:** Array, Hash Table
**Language:** C++

## Intuition

We need to find whether the array contains two equal numbers whose index difference is less than or equal to `k`.

We can use an `unordered_map` to store each number and its most recent index.

## Approach

1. Create an `unordered_map<int, int>` to store numbers and their indexes.
2. Traverse the array using an indexed `for` loop.
3. Check whether the current number already exists in the map.
4. If it exists, calculate the distance between the current index and its previously stored index.
5. If the distance is less than or equal to `k`, return `true`.
6. Update the number's index in the map.
7. If no valid pair is found, return `false`.

## Complexity

- **Time Complexity:** O(n) — We traverse the array once. Map operations take O(1) average time.
- **Space Complexity:** O(n) — The map can store up to n different numbers.

## Code

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            if(mp.count(n)) {
                int distance = abs(i - mp[n]);

                if(distance <= k) {
                    return true;
                }
            }

            mp[n] = i;
        }

        return false;
    }
};
```

## Important C++ Concepts

- `unordered_map<int, int>`: Stores a number as the key and its index as the value.
- `mp.count(n)`: Checks whether the number already exists in the map.
- `mp[n] = i`: Stores or updates the number's latest index.
- `abs()`: Returns the absolute (positive) difference between two indexes.
