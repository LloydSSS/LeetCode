// https://leetcode.com/problems/house-robber-ii/
// dp[i]表示抢劫从0～i的house的最大收益
// 考虑首尾相连，如果抢了第一家就不能抢最后一家，计算两次，可以复用一个数组

#include "lc.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (0 == n) return 0;
        if (1 == n) return nums[0];
        vector<int> dp(n+1, 0);
        dp[2] = nums[1];
        for (int i = 3; i <= n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        dp[1] = nums[0];
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        return max(dp[n], dp[n-1]);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
