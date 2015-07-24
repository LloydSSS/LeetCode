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
        srand(time(0));
        int n = nums.size();
        int l = 0, r = n-1, pivot = 0;
        while (true) {
            pivot = l + rand()%(r-l+1);
            pivot = partition(nums, l, r, nums[pivot]);
            if (pivot == k-1)
                break;
            if (pivot > k-1)
                r = pivot-1;
            else
                l = pivot+1;
        }
        return nums[pivot];
    }

    // int partition(vector<int> &nums, int l, int r, int pivot) {
    //     while (l < r) {
    //         while (l < pivot && nums[l] <= nums[pivot]) l++;
    //         swap(nums[l], nums[pivot]);
    //         pivot = l;
    //         while (pivot < r && nums[r] > nums[pivot]) r--;
    //         swap(nums[r], nums[pivot]);
    //         pivot = r;
    //     }
    //     return pivot;
    // }
    int partition(vector<int> &nums, int left, int right, int pivot) {
        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot)
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
