// https://leetcode.com/problems/longest-valid-parentheses/
// dp
// 栈

#include "lc.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int max_len = 0;
        vector<int> dp(len, 0);

        for (int i = 1; i < len; ++i) {
            if (s[i] == ')') {
                int j = i-dp[i-1]-1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = dp[i-1]+2;
                    if (j-1 >= 0)
                        dp[i] += dp[j-1];
                }
            }
            if (dp[i] > max_len)
                max_len = dp[i];
        }
        return max_len;
    }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<bool> flag(len, false);
        stack<int> st;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')' && !st.empty()) {
                int j = st.top();
                flag[i] = flag[j] = true;
                st.pop();
            }
        }
        int max_len = 0, cur_len = 0;
        for (int i = 0; i < len; ++i) {
            if (flag[i]) cur_len++;
            else {
                cur_len = 0;
            }
            max_len = max(cur_len, max_len);
        }
        return max_len;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
