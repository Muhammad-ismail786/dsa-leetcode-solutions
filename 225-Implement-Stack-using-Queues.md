
# 225. Implement Stack using Queues

**Difficulty:** Easy

**Topics:** Stack, Queue, Design

## Intuition

We need to implement a Stack using two Queues.

A Stack follows LIFO (Last In, First Out), which means the last inserted element is removed first.

A Queue follows FIFO (First In, First Out), which means the first inserted element is removed first.

We use two queues (`q1` and `q2`) to make the Queue behave like a Stack.

Whenever we insert a new element, we add it to `q2` first, then move all elements from `q1` to `q2`. Finally, we swap both queues so that the newest element always stays at the front of `q1`.

## Approach

1. **Push(x):**
   - Insert `x` into `q2`.
   - Move all elements from `q1` to `q2`.
   - Swap `q1` and `q2`.
   - The newest element is now at the front of `q1`.

2. **Pop():**
   - Check if `q1` is empty.
   - If empty, return `-1`.
   - Otherwise, store the front element.
   - Remove it using `q1.pop()`.
   - Return the removed element.

3. **Top():**
   - If `q1` is empty, return `-1`.
   - Otherwise, return `q1.front()`.

4. **Empty():**
   - Return whether `q1` is empty.

## Complexity

- **Time Complexity:**
  - Push: O(n)
  - Pop: O(1)
  - Top: O(1)
  - Empty: O(1)

- **Space Complexity:** O(n)

## Code

```cpp
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    void push(int x) {
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        if(q1.empty()){
            return -1;
        }

        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        if(q1.empty()){
            return -1;
        }

        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
```
