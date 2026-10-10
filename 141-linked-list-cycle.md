# Intuition

We need to determine whether a linked list contains a cycle.

A cycle exists when a node's `next` pointer points to a previously visited node.

We can solve this problem using two pointers:
- `slow` moves one step at a time.
- `fast` moves two steps at a time.

If a cycle exists, the fast pointer will eventually meet the slow pointer.

# Approach

1. Initialize both `slow` and `fast` pointers to `head`.
2. Use a `while` loop to check that `fast` and `fast->next` are not `NULL`.
3. Move `slow` one step forward using `slow->next`.
4. Move `fast` two steps forward using `fast->next->next`.
5. If `slow == fast`, return `true` because a cycle exists.
6. If the loop ends, return `false` because the linked list has no cycle.

# Complexity

- **Time complexity:** \(O(n)\) — The pointers traverse the linked list, and cycle detection takes linear time.
- **Space complexity:** \(O(1)\) — We use only two pointers and no additional data structures.

# Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
```
