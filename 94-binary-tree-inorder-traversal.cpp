class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || s.empty() == false) {

            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }

        return ans;
    }
};
