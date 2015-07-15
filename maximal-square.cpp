// http://www.lintcode.com/en/problem/maximal-square/
// Time:O(nm) Space:O(nm)
// dp[i][j]表示以i，j为右下角点的最大square
// 则dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;

#include "lc.h"

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        int ans = 0;
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0];
            ans = max(ans, dp[i][0]);
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
            ans = max(ans, dp[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1)
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
