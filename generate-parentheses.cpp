// https://leetcode.com/problems/generate-parentheses/
// a. dp[i]表示i个括号的所有序列，dp[i] = "(" dp[j] ")" + dp[i-j-1]
// b. dfs。纪录左括号和右括号剩余的数目，当左括号数目大于0时，可以添加一个左括号，当剩余左括号数目小于右括号数目时，可以添加一个右括号，当左右括号数都为0时，得到一个结果

#include "lc.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > dp(n+1);
        dp[0].push_back("");
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < dp[j].size(); ++k) {
                    for (int l = 0; l < dp[i-j-1].size(); ++l) {
                        string line = "(" + dp[j][k] + ")" + dp[i-j-1][l];
                        dp[i].push_back(line);
                    }
                }
            }
        }
        return dp[n];
    }
};

class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(n, n, s);
        return ans;
    }

    vector<string> ans;
    void dfs(int leftNum, int rightNum, string s) {
        if(leftNum == 0 && rightNum == 0) {
            ans.push_back(s);
        }
        if(leftNum > 0) {
            dfs(leftNum-1, rightNum, s+'(');
        }
        if(rightNum > 0 && leftNum < rightNum) {
            dfs(leftNum, rightNum-1, s+')');
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
