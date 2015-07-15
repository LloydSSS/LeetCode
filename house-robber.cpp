// http://www.lintcode.com/en/problem/house-robber/
// https://leetcode.com/problems/house-robber/
// dp[i]表示抢劫从0～i的house的最大收益

#include "lc.h"

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        if (A.size() == 0) return 0;
        vector<long long> dp(A.size()+1);
        dp[1] = A[0];
        long long ans = dp[1];
        for (int i = 2; i <= A.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+A[i-1]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
