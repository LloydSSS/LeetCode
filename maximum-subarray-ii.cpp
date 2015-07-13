// http://www.lintcode.com/en/problem/maximum-subarray-ii/
// 计算出向前向后以i结尾的最大子数组和，然后双指针遍历数组得到结果，l表示r之前最大的向后子数组和

#include "lintcode.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i-1] > 0 ? dp[i-1]+nums[i] : nums[i];
        }
        vector<int> dpr(nums.size());
        dpr[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; --i) {
            dpr[i] = dpr[i+1] > 0 ? dpr[i+1]+nums[i] : nums[i];
        }
        int ans = INT_MIN;
        int l = 0, r = 1;
        while (r < nums.size()) {
            if (ans < dp[l]+dpr[r])
                ans = dp[l]+dpr[r];
            if (dp[r] > dp[l])
                l = r;
            r++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(2);
    cout << sol.maxTwoSubArrays(v);
    return 0;
}
