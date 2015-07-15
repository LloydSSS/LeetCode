// http://www.lintcode.com/en/problem/unique-paths-ii/
// dp[i,j]表示到达(i,j)的路径数

#include "lc.h"

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int> > dp(2, vector<int>(n, 0));
        bool cur = 0;
        for (int i = 0; i < n && obstacleGrid[0][i] != 1; ++i)
            dp[cur][i] = 1;
        for (int j = 1; j < m; ++j) {
            cur = !cur;
            if (obstacleGrid[j][0] == 1)
                dp[cur][0] = 0;
            else
                dp[cur][0] = dp[!cur][0];
            for (int i = 1; i < n; ++i) {
                if (obstacleGrid[j][i] == 1)
                    dp[cur][i] = 0;
                else
                    dp[cur][i] = dp[cur][i-1] + dp[!cur][i];
            }
        }
        return dp[cur][n-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
