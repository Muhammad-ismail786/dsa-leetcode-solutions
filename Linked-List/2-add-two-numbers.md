# 2. Add Two Numbers

**LeetCode:** [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

**Difficulty:** Medium

**Topic:** Linked List

## Intuition

We are given two linked lists representing two non-negative integers. The digits are stored in reverse order.

Our task is to add both numbers and return the result as a new linked list.

For example:

- `l1 = [2, 4, 3]` represents `342`.
- `l2 = [5, 6, 4]` represents `465`.

The sum is `342 + 465 = 807`.

The result will be `[7, 0, 8]` because the digits are stored in reverse order.

We can solve this problem by adding corresponding digits one by one and handling the carry, just like normal addition.

## Approach

1. Create a dummy node with value `0` to build the result linked list.
2. Create a `current` pointer that points to the dummy node.
3. Initialize `carry = 0` to store the extra value from addition.
4. Use a `while` loop that continues while either linked list has nodes or carry is not zero.
5. Initialize `sum` with the current carry.
6. If `l1` is not `nullptr`, add its node value to `sum` and move `l1` to the next node.
7. If `l2` is not `nullptr`, add its node value to `sum` and move `l2` to the next node.
8. If `sum` is greater than or equal to `10`, set `carry = 1`; otherwise, set `carry = 0`.
9. Calculate the digit using `sum % 10`.
10. Create a new node with that digit and attach it to the result linked list.
11. Move `current` to the newly created node.
12. Return `dummy.next` because the dummy node is not part of the actual answer.

## Example Dry Run

**Input:**

```text
l1 = [2, 4, 3]
l2 = [5, 6, 4]
```

| Round | Calculation | Digit | Carry |
|---|---|---|---|
| 1 | 2 + 5 = 7 | 7 | 0 |
| 2 | 4 + 6 = 10 | 0 | 1 |
| 3 | 3 + 4 + 1 = 8 | 8 | 0 |

**Output:**

```text
[7, 0, 8]
```

## Complexity

- **Time Complexity:** `O(max(n, m))`

  We traverse both linked lists once, where `n` and `m` are the lengths of the two lists.

- **Space Complexity:** `O(max(n, m))`

  We create a new linked list to store the result.

## Code

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* current = &dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            int digit = sum % 10;

            current->next = new ListNode(digit);

            current = current->next;
        }

        return dummy.next;
    }
};
```
