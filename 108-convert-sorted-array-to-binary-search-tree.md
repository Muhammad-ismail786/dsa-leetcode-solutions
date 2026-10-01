# 108. Convert Sorted Array to Binary Search Tree

## Intuition

The array is sorted in ascending order.

To create a height-balanced Binary Search Tree, we choose the **middle element** as the root.

Then:

* The left part of the array becomes the left subtree.
* The right part of the array becomes the right subtree.
* We repeat the same process recursively.

If `start > end`, there are no elements left, so we return `nullptr`.

## Approach

1. Start with the complete array.
2. Find the middle index using:
   `start + (end - start) / 2`
3. Create a `TreeNode` using the middle element.
4. Recursively build the left subtree from `start` to `root - 1`.
5. Recursively build the right subtree from `root + 1` to `end`.
6. Return the created node.
7. If `start > end`, return `nullptr`.

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(log n)` for the recursion stack.

## Code

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    TreeNode* solve(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int root = start + (end - start) / 2;

        TreeNode* node = new TreeNode(nums[root]);

        node->left = solve(nums, start, root - 1);
        node->right = solve(nums, root + 1, end);

        return node;
    }
};
```
