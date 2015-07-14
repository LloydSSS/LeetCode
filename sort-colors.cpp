// http://www.lintcode.com/zh-cn/problem/maximum-subarray-difference/
// a. two-pass count
// b. one-pass two-pointer

#include "lintcode.h"

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        int cnt[3] = {0};
        for (int i = 0; i < nums.size(); ++i)
            cnt[nums[i]]++;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt[j] == 0) j++;
            nums[i] = j;
            cnt[j]--;
        }
    }
    void sortColors1pass(vector<int> &nums) {
        int i = 0, j = 0;
        for (int k = 0; k < nums.size(); ++k) {
            int v = nums[k];
            nums[k] = 2;
            if (v == 0) {
                nums[j++] = 1;
                nums[i++] = 0;
            } else if (v == 1) {
                nums[j++] = 1;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
