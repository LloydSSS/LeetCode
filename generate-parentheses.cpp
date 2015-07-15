// https://leetcode.com/problems/generate-parentheses/

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

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
