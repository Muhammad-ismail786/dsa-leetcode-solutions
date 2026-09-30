# 104. Maximum Depth of Binary Tree

## Problem

Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Intuition

For every node, we find the depth of its left and right subtrees.

The deeper subtree determines the maximum depth. We then add `1` for the current node.

If the tree is empty (`root == nullptr`), its depth is `0`.

## Approach

1. Check if the current node is `nullptr`.
2. If it is `nullptr`, return `0`.
3. Recursively find the maximum depth of the left subtree.
4. Recursively find the maximum depth of the right subtree.
5. Take the maximum of the left and right depths.
6. Add `1` for the current node.
7. Return the result.

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(h)`

Where:
- `n` = number of nodes in the binary tree.
- `h` = height of the binary tree.

## Code

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};