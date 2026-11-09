
# 257. Binary Tree Paths

**Difficulty:** Easy

**Topics:** Binary Tree, DFS, Recursion, String

## Intuition

We need to find all paths from the root node to every leaf node in a binary tree.

A leaf node is a node that has no left or right child.

We can use DFS (Depth-First Search) with Recursion to explore each path from the root to a leaf.

We store the current path as a string and save it when we reach a leaf node.

## Approach

1. Create a `vector<string>` named `result` to store all root-to-leaf paths.

2. Create a recursive DFS helper function that takes three parameters:
   - `node`: The current tree node.
   - `path`: The path from the root to the current node.
   - `result`: Reference to the vector that stores all paths.

3. If the current node is `nullptr`, return.

4. Convert the current node's value into a string using `to_string()` and append it to the current path.

5. Check whether the current node is a leaf node:
   - If both left and right children are `nullptr`, add the current path to `result` and return.

6. Append `"->"` to the path to separate the next node.

7. Recursively explore the left and right children.

8. Finally, return the result vector containing all root-to-leaf paths.

## Complexity

- Time Complexity: O(N × H)

  N is the number of nodes and H is the height of the tree. Each node is visited once, and building or copying path strings can take up to O(H) time per node.

- Space Complexity: O(N × H)

  The result stores all root-to-leaf paths. The recursion stack and path copies require additional space.

## Code

```cpp
class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (node == nullptr) {
            return;
        }

        path += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
            return;
        }

        path += "->";

        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        dfs(root, "", result);

        return result;
    }
};
```

## Example

**Input:**
```text
root = [1,2,3,null,5]
```

**Output:**
```text
["1->2->5", "1->3"]
```
