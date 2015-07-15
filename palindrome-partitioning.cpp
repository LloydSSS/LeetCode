// http://www.lintcode.com/zh-cn/problem/palindrome-partitioning/
// dp+dfs

#include "lc.h"

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string> > partition(string s) {
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        vector<vector<string> > ans;
        vector<string> tran;
        gen(dp, s);
        dfs(ans, tran, dp, s, 0);
        return ans;
    }

    void dfs(vector<vector<string> > &ans, vector<string> &tran,
    vector<vector<bool> > &dp, string &s, int i) {
        if (i == s.size()) {
            ans.push_back(tran);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (dp[i][j]) {
                tran.push_back(s.substr(i, j-i+1));
                dfs(ans, tran, dp, s, j+1);
                tran.pop_back();
            }
        }
    }

    void gen(vector<vector<bool> > &dp, string &s) {
        for (int i = 0; i < dp.size(); ++i)
            dp[i][i] = true;

        for (int len = 1; len < dp.size(); ++len) {
            for (int i = 0; i+len < dp.size(); ++i) {
                int j = i+len;
                if (len == 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
