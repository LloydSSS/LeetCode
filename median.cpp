// http://www.lintcode.com/en/problem/median/
// 使用快速排序中的partition方法进行寻找

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        return kthSmallestElement((nums.size()+1)/2, nums);
    }
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthSmallestElement(int k, vector<int> nums) {
        if (k > nums.size()) return -1;
        int n = nums.size();
        int l = 0, r = n-1;
        while (l <= r) {
            int pivot = partition(nums, l, r);
            if (pivot == k-1)
                return nums[pivot];
            if (pivot > k-1)
                r = pivot-1;
            else
                l = pivot+1;
        }
        return -1;
    }

    int partition(vector<int> &nums, int l, int r) {
        srand(time(0));
        int pivot = l + rand()%(r-l+1);
        swap(nums[r], nums[pivot]);
        pivot = l-1;
        for (int i = l; i < r; ++i) {
            if (nums[i] < nums[r]) {
                ++pivot;
                swap(nums[pivot], nums[i]);
            }
        }
        ++pivot;
        swap(nums[pivot], nums[r]);
        return pivot;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
