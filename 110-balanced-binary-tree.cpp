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
