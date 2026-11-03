#include <iostream>
#include <algorithm>
using namespace std;

// Step 1: TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Step 2: Solution class
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == nullptr) {
            return nullptr;
        }

        swap(root->left, root->right);

        invertTree(root->left);

        invertTree(root->right);

        return root;
    }
};

// Step 3: Tree print karne ka function
void printTree(TreeNode* root) {

    if (root == nullptr) {
        return;
    }

    cout << root->val << " ";

    printTree(root->left);
    printTree(root->right);
}

// Step 4: Main function
int main() {

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original Tree: ";
    printTree(root);

    Solution obj;

    root = obj.invertTree(root);

    cout << "\nInverted Tree: ";
    printTree(root);

    return 0;
}
