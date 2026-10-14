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
