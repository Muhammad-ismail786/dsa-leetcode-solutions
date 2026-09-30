# 104. Maximum Depth of Binary Tree

## Problem

Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Intuition

For every node, we need to find the depth of its left subtree and right subtree.

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

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(h)`

Where:

* `n` = number of nodes in the binary tree.
* `h` = height of the binary tree.

## Code

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
```

## Example

### Input

```text
root = [3,9,20,null,null,15,7]
```

### Binary Tree

```text
        3
       / \
      9   20
         /  \
        15   7
```

### Output

```text
3
```

### Explanation

The longest paths are:

```text
3 → 20 → 15
```

or

```text
3 → 20 → 7
```

Each path contains `3` nodes, so the maximum depth is `3`.

## Key Concept

This problem uses **recursion** and **Depth-First Search (DFS)**.

For every node:

```text
Maximum Depth =
1 + max(left subtree depth, right subtree depth)
```

The `1` represents the current node.
