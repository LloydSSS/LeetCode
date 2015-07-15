// http://www.lintcode.com/en/problem/3-sum-closest/
// https://leetcode.com/problems/3sum-closest/
// Time: O(n2), Space: O(1)
// 排序，三个指针，固定第一个指针之后，另外两个指针左右夹逼

#include "lc.h"

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int gap = INT_MAX, ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    k--;
                } else {
                    j++;
                }
                if (abs(sum - target) < gap) {
                    gap = abs(sum - target);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
