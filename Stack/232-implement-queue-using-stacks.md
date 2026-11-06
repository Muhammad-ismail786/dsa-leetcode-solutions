# 232. Implement Queue using Stacks (C++)

## Intuition

A Queue follows FIFO (First In, First Out), which means the element inserted first must be removed first.

A Stack follows LIFO (Last In, First Out), which means the last inserted element is removed first.

We can implement a Queue using two stacks (`s1` and `s2`).

- `s1` is used to insert new elements.
- `s2` is used to access and remove the front element.

When `s2` is empty, we transfer all elements from `s1` to `s2`. This reverses their order and gives us the correct FIFO behavior.

## Approach

1. **push(x):**
   - Insert the new element into `s1` using `push()`.
   - This operation takes O(1) time.

2. **pop():**
   - If `s2` is empty, transfer all elements from `s1` to `s2`.
   - Remove and return the top element of `s2`.

3. **peek():**
   - If `s2` is empty, transfer all elements from `s1` to `s2`.
   - Return the top element of `s2` without removing it.

4. **empty():**
   - Return true only when both `s1` and `s2` are empty.

## Complexity

- **Time complexity:**
  - `push()`: O(1)
  - `pop()`: Amortized O(1)
  - `peek()`: Amortized O(1)
  - `empty()`: O(1)
  - Overall: O(n) for n operations.

- **Space complexity:** O(n), where n is the number of elements stored in the Queue.

## Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();

        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
```

## Example

**Input:**
```text
push(1)
push(2)
peek()
pop()
peek()
empty()
```

**Output:**
```text
1
1
2
false
```

## Key Learning

- Queue follows FIFO.
- Stack follows LIFO.
- Two stacks can be used to implement a Queue.
- Transfer elements only when `s2` is empty.
- Each element is transferred at most once, giving amortized O(1) time complexity.
