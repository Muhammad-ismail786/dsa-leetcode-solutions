# Binary Tree Inorder Traversal

## Intuition

Inorder traversal mein tree ko is order mein visit karna hota hai:

**Left → Root → Right**

Recursive solution ki jagah hum ek **stack** use karte hain.

Sab se pehle left side ke nodes ko stack mein store karte hain. Jab left side complete ho jati hai, stack se node nikal kar uski value answer mein add karte hain, phir uske right subtree par move karte hain.

## Approach

1. Ek `vector` banaya `ans` jo final answer store karega.
2. Ek `stack` banaya jo nodes ko temporarily store karega.
3. `curr` ko root se start kiya.
4. Jab tak `curr` available hai ya stack empty nahi hai:

   * Current node aur uske left nodes ko stack mein push karte hain.
   * Stack ke top node ko pop karte hain.
   * Us node ki value `ans` mein add karte hain.
   * Phir uske right node par move karte hain.
5. End mein `ans` return kar dete hain.

## Complexity

* Time complexity: **O(n)**
* Space complexity: **O(n)**

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
```
