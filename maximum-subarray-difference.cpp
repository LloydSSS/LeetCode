// http://www.lintcode.com/zh-cn/problem/maximum-subarray-difference/
// 纪录lmax, lmin, rmax, rmin分别表示从左或从右边开始以i结尾的最大子数组和最小子数组和

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> lmax(nums.size());
        vector<int> lmin(nums.size());

        lmax[0] = lmin[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            lmax[i] = lmax[i-1] > 0 ? lmax[i-1]+nums[i] : nums[i];
            lmin[i] = lmin[i-1] < 0 ? lmin[i-1]+nums[i] : nums[i];
        }

        vector<int> rmax(nums.size());
        vector<int> rmin(nums.size());
        rmax[nums.size()-1] = rmin[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; --i) {
            rmax[i] = rmax[i+1] > 0 ? rmax[i+1]+nums[i] : nums[i];
            rmin[i] = rmin[i+1] < 0 ? rmin[i+1]+nums[i] : nums[i];
        }

        int ans = INT_MIN;
        int l = 0, ll = 0, r = 1;
        for (r = 1; r < nums.size(); ++r) {
            if (ans < lmax[l]-rmin[r])
                ans = lmax[l]-rmin[r];
            if (ans < rmax[r]-lmin[ll])
                ans = rmax[r]-lmin[ll];
            if (lmin[r] < lmin[ll])
                ll = r;
            if (lmax[r] > lmax[l])
                l = r;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
