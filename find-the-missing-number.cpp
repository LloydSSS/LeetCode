// http://www.lintcode.com/en/problem/find-the-missing-number/
// 桶排序

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] >= 0 && nums[i] < nums.size()
                && nums[i] != i && nums[nums[i]] != nums[i])
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
