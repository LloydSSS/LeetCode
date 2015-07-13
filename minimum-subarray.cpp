// http://www.lintcode.com/en/problem/minimum-subarray/
// 同maximum subarray

#include "lintcode.h"

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i-1] < 0 ? dp[i-1]+nums[i] : nums[i];
            if (dp[i] < ans)
                ans = dp[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
