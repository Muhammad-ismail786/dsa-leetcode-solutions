# Intuition
The main idea is to use two pointers, `pA` and `pB`, to traverse both linked lists. If the pointers reach the end of their respective lists, redirect them to the beginning of the other list. This helps both pointers travel the same total distance. If the lists intersect, both pointers will eventually meet at the same node. Otherwise, both will become `nullptr`.

# Approach
1. Initialize `pA` with `headA` and `pB` with `headB`.
2. Continue the loop while `pA` and `pB` do not point to the same node.
3. If `pA` reaches `nullptr`, redirect it to `headB`; otherwise, move it to the next node.
4. If `pB` reaches `nullptr`, redirect it to `headA`; otherwise, move it to the next node.
5. When both pointers point to the same node, return that node. If there is no intersection, both pointers eventually meet at `nullptr`.

# Complexity
- Time complexity: \(O(m+n)\), where \(m\) and \(n\) are the lengths of the two linked lists.
- Space complexity: \(O(1)\), because only two pointers are used and no extra data structure is required.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};
```
