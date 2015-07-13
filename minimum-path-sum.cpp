// http://www.lintcode.com/en/problem/minimum-path-sum/
// dp[i][j]表示到(i, j)的最小路径和

#include "lintcode.h"

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0 && grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i)
            dp[0][i] = grid[0][i] + dp[0][i-1];
        for (int i = 1; i < m; ++i)
            dp[i][0] = grid[i][0] + dp[i-1][0];
        for (int j = 1; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                dp[j][i] = min(dp[j-1][i], dp[j][i-1]) + grid[j][i];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
