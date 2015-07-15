// http://www.lintcode.com/en/problem/valid-parentheses/
// 使用栈来未匹配结果，如果来的是左括号，压栈，如果右括号：匹配，弹栈；不匹配,返回错误

#include "lc.h"

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        stack<char> st;
        map<char, char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (!st.empty() && s[i] == mp[st.top()]) {
                st.pop();
            } else
                return false;
        }
        return st.empty();
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
