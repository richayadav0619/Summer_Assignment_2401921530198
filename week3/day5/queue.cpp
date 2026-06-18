#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        peek();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Front after pop: " << q.peek() << endl;

    return 0;
}