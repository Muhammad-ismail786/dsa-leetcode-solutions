
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
