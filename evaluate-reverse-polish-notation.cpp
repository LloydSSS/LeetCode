// http://www.lintcode.com/en/problem/evaluate-reverse-polish-notation/
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// 栈，按照运算符，操作数、操作数顺序计算即可

#include "lc.h"

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                switch (tokens[i][0]) {
                    case '+':
                        st.push(a+b);
                        break;
                    case '-':
                        st.push(a-b);
                        break;
                    case '*':
                        st.push(a*b);
                        break;
                    case '/':
                        st.push(a/b);
                        break;
                }
            } else
                st.push(atoi(tokens[i].c_str()));
        }
        return st.top();
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
