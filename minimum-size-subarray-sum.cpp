// http://www.lintcode.com/en/problem/minimum-subarray/
// https://leetcode.com/problems/minimum-size-subarray-sum/
// 双指针遍历

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        if (nums.size() == 0) return -1;
        int p1 = 0; int p2 = 0;
        int ans = INT_MAX;
        int sum = nums[0];
        while (p1 <= p2 && p2 < nums.size()) {
            if (sum < s) {
                p2++;
                sum += nums[p2];
            } else {
                ans = min(ans, p2-p1+1);
                sum -= nums[p1];
                p1++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
