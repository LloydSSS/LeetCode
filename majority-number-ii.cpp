// Majority Number II
// http://www.lintcode.com/en/problem/majority-number-ii/
// https://leetcode.com/problems/majority-element-ii/
// 三三抵消，注意最后要重新统计一次

#include "lintcode.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        int cand1, cand2;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt1 == 0 || cand1 == nums[i]) {
                cand1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0 || cand2 == nums[i]) {
                cand2 = nums[i];
                cnt2++;
            } else {
                cnt1--, cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cand1 == nums[i])
                cnt1++;
            if (cand2 == nums[i])
                cnt2++;
        }
        if (cnt1 > cnt2)
            return cand1;
        else
            return cand2;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
