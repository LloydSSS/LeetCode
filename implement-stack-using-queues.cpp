// https://leetcode.com/problems/implement-stack-using-queues/
// 没有找到更好的办法，压栈时必须把一个队列清空

#include "lc.h"

class Stack {
public:
    Stack() : cur(false) {}
    // Push element x onto stack.
    void push(int x) {
        q[!cur].push(x);
        while (!q[cur].empty()) {
            q[!cur].push(q[cur].front());
            q[cur].pop();
        }
        cur = !cur;
    }

    // Removes the element on top of the stack.
    void pop() {
        q[cur].pop();
    }

    // Get the top element.
    int top() {
        return q[cur].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[!cur].empty() && q[cur].empty();
    }
private:
    queue<int> q[2];
    bool cur;
};

int main(int argc, char const *argv[]) {
    Stack st;
    st.push(1);
    st.pop();
    cout << st.empty() << endl;
    return 0;
}
