# 226. Invert Binary Tree

## Intuition

The problem asks us to invert a binary tree by swapping the left and right children of every node.

We can use recursion to visit every node and swap its left and right children.

## Approach

1. Check if the root is `nullptr`. If it is, return `nullptr`.
2. Swap the current node's left and right children using `swap()`.
3. Recursively invert the left subtree.
4. Recursively invert the right subtree.
5. Finally, return the root of the inverted tree.

## Complexity

- **Time Complexity:** \(O(n)\) — We visit every node exactly once.
- **Space Complexity:** \(O(h)\) — Recursion uses stack space proportional to the height of the tree. In the worst case, it can be \(O(n)\).

## Code

See [226-invert-binary-tree.cpp](226-invert-binary-tree.cpp).
