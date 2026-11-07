
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

int main() {

    // Input values
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Print Linked List
    cout << "Linked List: ";

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    // Check Palindrome
    Solution solution;

    bool result = solution.isPalindrome(head);

    cout << "Is Palindrome: ";

    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
