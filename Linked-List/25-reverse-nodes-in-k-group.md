
# 25. Reverse Nodes in k-Group

**Difficulty:** Hard

**Topics:** Linked List, Recursion, Pointer Manipulation

**Language:** C++

## Problem

Given the head of a linked list, reverse the nodes of the list `k` at a time.

If the number of remaining nodes is less than `k`, leave those nodes unchanged.

You may not change the values in the nodes. Only the nodes themselves may be changed.

## Example 1

**Input:**
```text
head = [1,2,3,4,5], k = 2
```

**Output:**
```text
[2,1,4,3,5]
```

## Example 2

**Input:**
```text
head = [1,2,3,4,5], k = 3
```

**Output:**
```text
[3,2,1,4,5]
```

## Intuition

We need to reverse the linked list in groups of `k` nodes.

We can use recursion to process each group separately.

Before reversing a group, we first check whether at least `k` nodes are available.

If fewer than `k` nodes remain, we return the list without changing those nodes.

## Approach

1. Initialize a temporary pointer `temp` with `head`.
2. Traverse `k` nodes to check whether a complete group is available.
3. If `temp` becomes `nullptr`, return `head` because the remaining nodes should not be reversed.
4. Initialize three pointers:
   - `prev = nullptr`
   - `curr = head`
   - `next = nullptr`
5. Reverse exactly `k` nodes using these three pointers.
6. Recursively call `reverseKGroup(curr, k)` to reverse the remaining groups.
7. Connect the last node of the current reversed group to the result of the recursive call.
8. Return `prev`, which points to the new head of the current group.

## Complexity

- **Time Complexity:** `O(n)` — Each node is visited a constant number of times.
- **Space Complexity:** `O(n/k)` — Recursive calls use stack space for each group. In the worst case, this becomes `O(n)` when `k = 1`.

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Step 1: Check if k nodes are available
        ListNode* temp = head;

        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                return head;
            }

            temp = temp->next;
        }

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Connect remaining nodes
        head->next = reverseKGroup(curr, k);

        // Step 4: Return new head
        return prev;
    }
};
```

## Key Learning

- `temp` checks whether a complete group of `k` nodes exists.
- `prev` stores the previous node during reversal.
- `curr` points to the current node.
- `next` saves the next node before changing a link.
- Recursion processes the remaining groups.
- Only `next` pointers are changed; node values remain unchanged.
