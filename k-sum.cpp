// k Sum
// http://www.lintcode.com/en/problem/k-sum/
// Time, Space:O(n*k*target)
// dp[i][j][t] denotes the number of ways to select, from first i elements, j elements whose sum equals to t

#include "lintcode.h"

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        int n = A.size();
        // dp[i][j][t] denotes the number of ways to select,
        // from first i elements, j elements whose sum equals to t
        vector<vector<vector<int> > > dp(n+1,
                    vector<vector<int>>(k+1, vector<int>(target+1, 0)));

        for (int i = 1; i <= n; ++i)
            if (A[i-1] <= target)
                for (int j = i; j <= n; ++j)
                    dp[j][1][A[i-1]] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= min(i, k); ++j) {
                for (int t = 1; t <= target; ++t) {
                    dp[i][j][t] = dp[i-1][j][t];
                    if (t-A[i-1] >= 0) {
                        dp[i][j][t] += dp[i-1][j-1][t-A[i-1]];
                    }
                }
            }
        }
        return dp[n][k][target];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
