// http://www.lintcode.com/en/problem/subarray-sum-ii/
// a. Time:O(n2) Space:O(n) 先求出前缀和，然后枚举求两个前缀和的差
// b. Time:O(nlogn) Space:O(n) 先求出前缀和，然后二分找出上界下界，前提是数组非负

#include "lc.h"

class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& nums, int start, int end) {
        return subarraySumIIOnlogn(nums, start, end);
        int ans = 0;
        vector<int> sum(nums.size()+1);
        partial_sum(nums.begin(), nums.end(), sum.begin()+1);

        for (int i = 0; i < sum.size(); ++i) {
            for (int j = i+1; j < sum.size(); ++j) {
                if (sum[j]-sum[i] >= start && sum[j]-sum[i] <= end)
                    ans++;
            }
        }
        return ans;
    }

    int subarraySumIIOnlogn(vector<int>& nums, int start, int end) {
        int ans = 0;
        vector<int> sum(nums.size()+1);
        partial_sum(nums.begin(), nums.end(), sum.begin()+1);

        for (int i = 0; i < sum.size(); ++i) {
            auto left = lower_bound(sum.begin(),
                                    sum.begin()+i+1,
                                    sum[i]-end);
            auto right = upper_bound(sum.begin(),
                                    sum.begin()+i+1,
                                    sum[i]-start);
            ans += right-left;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
