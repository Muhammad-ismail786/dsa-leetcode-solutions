# 110. Balanced Binary Tree

## Intuition

A binary tree is height-balanced if, for every node, the height difference between its left and right subtrees is at most `1`.

For each node:

* Find the height of the left subtree.
* Find the height of the right subtree.
* Check whether their height difference is greater than `1`.
* Recursively check the left and right subtrees.

The `getBSTHeight()` helper function calculates the height of each subtree recursively.

If the current node is `nullptr`, its height is `0`.

## Approach

1. If the tree is empty, return `true`.
2. Calculate the height of the left subtree.
3. Calculate the height of the right subtree.
4. If the difference between the two heights is greater than `1`, return `false`.
5. Recursively check whether the left subtree is balanced.
6. Recursively check whether the right subtree is balanced.
7. Return `true` only if both subtrees are balanced.
8. Calculate the height of each node using:
   `1 + max(leftHeight, rightHeight)`.

## Complexity

* **Time Complexity:** `O(n²)` in the worst case because subtree heights can be recalculated for multiple nodes.
* **Space Complexity:** `O(n)` in the worst case due to the recursion stack.

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

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int leftHeight = getBSTHeight(root->left);
        int rightHeight = getBSTHeight(root->right);

        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getBSTHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = getBSTHeight(root->left);
        int rightHeight = getBSTHeight(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

};
```
