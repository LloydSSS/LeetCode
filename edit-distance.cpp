// http://www.lintcode.com/en/problem/edit-distance/
// https://leetcode.com/problems/edit-distance/
// dp[i,j] 表示word1[0~i], word2[0~j]之间的编辑距离

#include "lc.h"

class Solution {
public:
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) return n;
        if (n == 0) return m;
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
