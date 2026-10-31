# 217. Contains Duplicate

## Intuition

We need to check whether the given array contains any duplicate numbers.

We can use an `unordered_set` to store numbers we have already visited. If a number is already present in the set, it means a duplicate exists, so we return `true`.

## Approach

1. Create an empty `unordered_set<int>` named `seen`.
2. Iterate through each number in the array using a for loop.
3. Check whether the current number already exists in `seen` using `seen.count(n)`.
4. If the number exists, return `true`.
5. Otherwise, insert the number into the set using `seen.insert(n)`.
6. If the loop finishes without finding any duplicate, return `false`.

## Complexity

- **Time Complexity:** O(n) average — We traverse the array once. Searching and inserting in an unordered set take O(1) average time.
- **Space Complexity:** O(n) — In the worst case, the set stores all unique numbers.

## Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int n : nums) {
            if (seen.count(n)) {
                return true;
            }

            seen.insert(n);
        }

        return false;
    }
};
```
