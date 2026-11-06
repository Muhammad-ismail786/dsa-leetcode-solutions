
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

    // Insert element
    void push(int x) {
        s1.push(x);
    }

    // Remove and return front element
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

    // Return front element without removing
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check whether queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);

    cout << "Front element: " << myQueue.peek() << endl;

    cout << "Removed element: " << myQueue.pop() << endl;

    cout << "Front element after pop: " << myQueue.peek() << endl;

    cout << boolalpha;
    cout << "Is queue empty? " << myQueue.empty() << endl;

    myQueue.pop();

    cout << "Is queue empty after removing all elements? "
         << myQueue.empty() << endl;

    return 0;
}
