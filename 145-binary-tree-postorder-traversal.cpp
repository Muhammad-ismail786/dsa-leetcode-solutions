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
