# Merge Two Sorted Linked Lists – Two-Pointer Approach

## Problem

You are given the heads of two sorted linked lists, `list1` and `list2`.

Merge both lists into one sorted linked list and return the head of the merged list.

### Example

```text
list1 = [1, 2, 4]
list2 = [1, 3, 4]

Output = [1, 1, 2, 3, 4, 4]
```

---

## Intuition

We have two sorted linked lists.

We compare the current nodes of both lists and select the smaller value.

For example:

```text
list1: 1 → 2 → 4
list2: 1 → 3 → 4
```

We take the smaller node one by one and connect it to the result list.

---

## Approach

1. Create two pointers, `l1` and `l2`, for the two linked lists.
2. Create a dummy node called `result`.
3. Create a `current` pointer to build the merged list.
4. While both lists have nodes:

   * Compare `l1->val` and `l2->val`.
   * Attach the smaller node to `current->next`.
   * Move that list pointer to its next node.
   * Move `current` to the newly attached node.
5. When one list becomes `NULL`, attach the remaining nodes of the other list.
6. Return `result->next` because `result` is the dummy node.

---

## Complexity

* **Time Complexity:** `O(n + m)`
* **Space Complexity:** `O(1)`

Where `n` is the number of nodes in `list1` and `m` is the number of nodes in `list2`.

---

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        ListNode* result = new ListNode(0);
        ListNode* current = result;

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }

            current = current->next;
        }

        if (l1 != nullptr) {
            current->next = l1;
        }
        else {
            current->next = l2;
        }

        return result->next;
    }
};
```
