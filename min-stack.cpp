// http://www.lintcode.com/en/problem/min-stack/
// https://leetcode.com/problems/min-stack/
// 使用另外一个栈纪录最小值，如果新压栈的元素比栈顶元素小，则压栈
// 弹栈时如果该元素等于最小栈的栈顶元素，则最小栈也弹栈

#include "lc.h"

class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {

    }

    void push(int number) {
        st.push(number);
        if (minst.empty() || minst.top() >= number)
            minst.push(number);
    }

    int pop() {
        int retv = st.top();
        st.pop();
        if (retv == minst.top())
            minst.pop();
        return retv;
    }

    int min() {
        return minst.top();
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
