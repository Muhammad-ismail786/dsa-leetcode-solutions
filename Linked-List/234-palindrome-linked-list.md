# 234. Palindrome Linked List

## # Intuition

The idea is to check whether a Linked List reads the same forward and backward.

For example:

`1 → 2 → 2 → 1`

This is a Palindrome because the values are the same from both directions.

We can solve this problem using the Fast and Slow Pointer approach.

- Use two pointers, `slow` and `fast`, to find the middle of the Linked List.
- Reverse the second half of the Linked List.
- Compare the first half with the reversed second half.
- If all values match, return `true`; otherwise, return `false`.

## # Approach

**Step 1: Find the Middle**

- `slow` moves one node at a time.
- `fast` moves two nodes at a time.
- When `fast` reaches the end, `slow` reaches the middle.

**Step 2: Reverse the Second Half**

Use three pointers:

- `prev`: Stores the previous node.
- `curr`: Points to the current node.
- `next`: Temporarily stores the next node.

Reverse the links of the second half.

**Step 3: Compare Both Halves**

- Start one pointer from `head`.
- Start another pointer from `prev`.
- Compare their values one by one.
- If any values are different, return `false`.
- If all values match, return `true`.

## # Complexity

- Time complexity: `O(n)`

We traverse the Linked List to find the middle, reverse the second half, and compare both halves.

- Space complexity: `O(1)`

We use only a few pointers and no additional data structures.

## # Code

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // Step 1: Find Middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse Second Half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Compare Both Halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
```

## # Example 1

**Input:** `[1, 2, 2, 1]`

**Output:** `true`

## # Example 2

**Input:** `[1, 2, 3, 4]`

**Output:** `false`
