// http://www.lintcode.com/en/problem/longest-increasing-continuous-subsequence-ii/
// a. Time:O(mn) Space:O(mn) dfs＋记忆化搜索

#include "lc.h"

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        int ans = 0;
        int m = A.size();
        if (m == 0) return 0;
        int n = A[0].size();
        vector<vector<int> > dp(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(A, dp, i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int> > &A, vector<vector<int> > &dp, int i, int j) {
        if (dp[i][j] != 0)
            return;
        if (i > 0 && A[i-1][j] < A[i][j]) {
            dfs(A, dp, i-1, j);
            dp[i][j] = max(dp[i-1][j]+1, dp[i][j]);
        }
        if (i+1 < A.size() && A[i+1][j] < A[i][j]) {
            dfs(A, dp, i+1, j);
            dp[i][j] = max(dp[i+1][j]+1, dp[i][j]);
        }
        if (j > 0 && A[i][j-1] < A[i][j]) {
            dfs(A, dp, i, j-1);
            dp[i][j] = max(dp[i][j-1]+1, dp[i][j]);
        }
        if (j+1 < A[0].size() && A[i][j+1] < A[i][j]) {
            dfs(A, dp, i, j+1);
            dp[i][j] = max(dp[i][j+1]+1, dp[i][j]);
        }
        dp[i][j] = max(dp[i][j], 1);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
