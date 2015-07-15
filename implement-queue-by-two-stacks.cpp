// http://www.lintcode.com/en/problem/implement-queue-by-two-stacks/
// https://leetcode.com/problems/implement-queue-using-stacks/
// 水

#include "lc.h"

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
    }

    void push(int element) {
        stack1.push(element);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int retv = stack2.top();
        stack2.pop();
        return retv;
    }

    int top() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int retv = stack2.top();
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
