// http://www.lintcode.com/en/problem/minimum-adjustment-cost/
// dp[i,j] 表示第i个元素调整到j时的最小cost
// for each dp[i][j], minimum cost = minimum cost dp[i-1][j-target ... j+target] + abs(A[i]-j)
// 所以用三重循环，i，j，j-target...j+target

#include "lintcode.h"

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        int n = A.size();
        if (n <= 1) return 0;
        vector<vector<int> > dp(n, vector<int>(101, INT_MAX));
        for (int j = 1; j <= 100; ++j)
            dp[0][j] = abs(j-A[0]);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= 100; ++j) {
                int diff = abs(j-A[i]);
                int upper = min(j+target,100);
                int lower = max(j-target,1);
                for(int k = lower; k <= upper; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+diff);
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 1; j <= 100; ++j) {
            ans = min(dp[n-1][j], ans);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
