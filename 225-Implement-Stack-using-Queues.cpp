
#include <iostream>
#include <queue>
using namespace std;

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

int main() {
    MyStack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top: " << myStack.top() << endl;
    cout << "Pop: " << myStack.pop() << endl;
    cout << "Top: " << myStack.top() << endl;
    cout << "Is Empty: " << myStack.empty() << endl;

    return 0;
}
