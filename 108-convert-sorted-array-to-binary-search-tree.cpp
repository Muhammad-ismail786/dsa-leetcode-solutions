class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    TreeNode* solve(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int root = start + (end - start) / 2;

        TreeNode* node = new TreeNode(nums[root]);

        node->left = solve(nums, start, root - 1);
        node->right = solve(nums, root + 1, end);

        return node;
    }
};
