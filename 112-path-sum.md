# Path Sum — DFS Recursive Approach

## Intuition

We need to check if there is any path from the root node to a leaf node whose values add up to `targetSum`.

At each node, we subtract its value from `targetSum`. When we reach a leaf node, we check whether its value is equal to the remaining `targetSum`.

## Approach

* If the tree is empty, return `false`.
* Check if the current node is a leaf node.
* If it is a leaf, compare its value with `targetSum`.
* If it is not a leaf, subtract the current node's value from `targetSum`.
* Recursively check both the left and right subtrees.
* If either subtree contains a valid path, return `true`.

## Complexity

* Time complexity: **O(n)**
* Space complexity: **O(h)**

Where `n` is the number of nodes in the binary tree and `h` is the height of the tree.

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *     right(right) {}
 * };
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return root->val == targetSum;

        targetSum = targetSum - root->val;

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
```
