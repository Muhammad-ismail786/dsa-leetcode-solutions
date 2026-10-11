# Intuition

In preorder traversal, we visit the current node first, then traverse its left subtree, and finally traverse its right subtree.

The order is **Root → Left → Right**.

We use recursion to visit every node and a vector to store the values in traversal order.

# Approach

1. Create an empty vector `res` to store the traversal result.
2. Call `preOrder(root, res)` to start the traversal from the root node.
3. If the current node is `nullptr`, return because there is no node to visit.
4. Add the current node's value to the vector using `res.push_back(node->val)`.
5. Recursively traverse the left subtree using `preOrder(node->left, res)`.
6. Recursively traverse the right subtree using `preOrder(node->right, res)`.
7. Return the vector containing all node values.

We pass `res` by reference using `vector<int>& res` so that all recursive calls modify the same original vector instead of creating separate copies.

# Complexity

- **Time complexity:** \(O(n)\), where \(n\) is the number of nodes, because each node is visited once.
- **Space complexity:** \(O(n)\) for the result vector and the recursion call stack in the worst case.

# Code

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }

    void preOrder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) {
            return;
        }

        res.push_back(node->val);

        preOrder(node->left, res);
        preOrder(node->right, res);
    }
};
```
