// http://www.lintcode.com/en/problem/distinct-subsequences/
// https://leetcode.com/problems/distinct-subsequences/
// dp[i][j] 表示s[0~i],t[0~j]间distinct subsequences的个数
#include "lc.h"

class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct2D(string &S, string &T) {
        int m = S.size();
        int n = T.size();
        vector<vector<int> > dp(2, vector<int>(n+1, 0));
        bool cur = 0;
        dp[0][0] = 1;
        dp[1][0] = 1;
        for (int i = 1; i <= m; ++i) {
            cur = !cur;
            for (int j = 1; j <= n; ++j) {
                if (S[i-1] == T[j-1])
                    dp[cur][j] = dp[!cur][j-1]+dp[!cur][j];
                else
                    dp[cur][j] = dp[!cur][j];
            }
        }
        return dp[cur][n];
    }

    int numDistinct(string &S, string &T) {
        return numDistinct2D(S, T);
        vector<vector<int> > dp(S.size()+1, vector<int>(T.size()+1, 0));
        for (int i = 0; i <= S.size(); ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= S.size(); ++i) {
            for (int j = 1; j <= T.size(); ++j) {
                if (S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[S.size()][T.size()];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
