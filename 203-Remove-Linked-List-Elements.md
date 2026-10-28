
# 203. Remove Linked List Elements

## Intuition
We need to remove all nodes whose value is equal to `val` from the linked list.

## Approach
- Use `current` to traverse the linked list.
- Use `previous` to keep track of the previous node.
- If `current->val == val`:
  - If `current` is the head, move `head` to the next node.
  - Otherwise, connect the previous node to the next node of `current`.
- If the current node does not match `val`, update `previous`.
- Move `current` to the next node.
- Return the updated `head`.

## Complexity
- Time complexity: O(n)
- Space complexity: O(1)

## Code
See `203-Remove-Linked-List-Elements.cpp`.
