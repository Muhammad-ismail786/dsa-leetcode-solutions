
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

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

// Print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

// Main function
int main() {

    int n, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {

        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "\nOriginal List: ";
    printList(head);

    Solution solution;

    head = solution.reverseKGroup(head, k);

    cout << "After Reversing: ";
    printList(head);

    return 0;
}
