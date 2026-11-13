
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Linked List Node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Compare nodes for Min Heap
struct Compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Create Min Heap
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > minHeap;

        // Insert first node of every non-empty list
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        // Create dummy node
        ListNode dummy(0);
        ListNode* current = &dummy;

        // Merge all linked lists
        while (!minHeap.empty()) {

            // Get the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Attach smallest node to result
            current->next = smallest;
            current = current->next;

            // Insert next node from the same list
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
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

// Delete linked list nodes
void deleteList(ListNode* head) {

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    // First list: 1 -> 4 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    // Second list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Third list: 2 -> 6
    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    // Store all linked lists in vector
    vector<ListNode*> lists = {
        list1,
        list2,
        list3
    };

    // Create Solution object
    Solution solution;

    // Merge all linked lists
    ListNode* result = solution.mergeKLists(lists);

    // Print merged linked list
    cout << "Merged Linked List: ";
    printList(result);

    // Free allocated memory
    deleteList(result);

    return 0;
}
