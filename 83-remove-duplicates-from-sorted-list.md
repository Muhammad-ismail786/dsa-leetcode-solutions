# Remove Duplicates from Sorted List

## Intuition

The linked list is already sorted, so duplicate values will always be next to each other.

For example:

```text
1 → 1 → 2 → 3 → 3
```

We can use a `current` pointer and compare:

```text
current node
     ↓
    [1] → [1]
            ↑
       current->next
```

If both values are the same, the second node is a duplicate, so we skip it.

---

## Approach

1. If the list is empty, return `head`.
2. Create a pointer called `current` and start it from `head`.
3. Continue while `current->next` exists.
4. Compare the current node's value with the next node's value.
5. If both values are equal:

   * Skip the duplicate node using:

   ```cpp
   current->next = current->next->next;
   ```
6. If the values are different:

   * Move `current` to the next node.
7. Return `head`.

### Example

Input:

```text
1 → 1 → 2 → 3 → 3
```

After removing duplicates:

```text
1 → 2 → 3
```

---

## Complexity

* Time complexity: \(O(n)\)
* Space complexity: \(O(1)\)

We visit each node at most a constant number of times and use only one pointer.

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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) {
            return head;
        }

        ListNode* current = head;

        while (current->next != nullptr) {

            if (current->val == current->next->val) {
                current->next = current->next->next;
            }
            else {
                current = current->next;
            }
        }

        return head;
    }
};
```
