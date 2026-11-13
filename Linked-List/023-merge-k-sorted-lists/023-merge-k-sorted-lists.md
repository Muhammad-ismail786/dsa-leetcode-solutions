
# 23. Merge k Sorted Lists

**Difficulty:** Hard

**Topic:** Linked List, Heap, Priority Queue

**Language:** C++

## Problem Description

You are given an array of `k` linked lists, where each linked list is sorted in ascending order.

Merge all the linked lists into one sorted linked list and return its head.

### Example

**Input:**

```text
lists = [
    1 -> 4 -> 5,
    1 -> 3 -> 4,
    2 -> 6
]
```

**Output:**

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
```

## Intuition

We are given `k` sorted linked lists. We need to merge all of them into one sorted linked list.

Instead of comparing every node manually, we can use a Min Heap (Priority Queue) to efficiently find the smallest available node.

Initially, we insert the first node of every non-empty linked list into the Min Heap.

The Min Heap always gives us the smallest node. We remove that node, attach it to our result list, and insert its next node into the heap.

We repeat this process until the heap becomes empty.

## Approach

1. Create a Min Heap to store linked list nodes.
2. Insert the first node of every non-empty linked list into the Min Heap.
3. Create a dummy node to simplify building the merged linked list.
4. While the Min Heap is not empty:
   - Get the smallest node using `top()`.
   - Remove it using `pop()`.
   - Attach it to the merged linked list.
   - Move the current pointer forward.
   - If the removed node has a next node, insert that next node into the Min Heap.
5. Return `dummy.next`, which is the head of the merged linked list.

## Complexity

- **Time Complexity:** O(N log k)
  - N is the total number of nodes across all linked lists.
  - k is the number of linked lists.
  - Every node is inserted into and removed from the Min Heap once.

- **Space Complexity:** O(k)
  - The Min Heap stores at most one available node from each linked list at a time.

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

class Compare {
public:
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

            // Get smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Attach node to result
            current->next = smallest;
            current = current->next;

            // Insert next node
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
```
