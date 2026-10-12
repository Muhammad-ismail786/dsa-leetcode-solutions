# Intuition
In postorder traversal, we visit the left subtree first, then the right subtree, and finally the root node. We can solve this problem using recursion by following this order for every node in the binary tree.

# Approach
1. Create an empty vector `res` to store the node values.
2. Call the helper function `postOrder()` with the root node and the result vector.
3. If the current node is `nullptr`, return without doing anything.
4. Recursively traverse the left subtree.
5. Recursively traverse the right subtree.
6. Add the current node's value to the result vector.
7. Return the result vector.

# Complexity
- Time complexity: \(O(n)\), where \(n\) is the number of nodes, because each node is visited exactly once.
- Space complexity: \(O(n)\) in the worst case due to the recursion stack for a skewed tree. The output vector also requires \(O(n)\) space.

# Code
```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }

    void postOrder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) {
            return;
        }

        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->val);
    }
};
```
