// http://www.lintcode.com/en/problem/evaluate-reverse-polish-notation/
// 栈，水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

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
