// http://www.lintcode.com/en/problem/kth-largest-element/
// 快速排序中的partition

#include "lintcode.h"

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        if (k > nums.size()) return -1;
        srand(time(0));
        int l = 0, r = nums.size()-1, pivot = 0;
        while (true) {
            pivot = l + rand()%(r-l+1);
            pivot = partition(nums, l, r, pivot);
            if (pivot == k-1)
                break;
            if (pivot > k-1)
                r = pivot-1;
            else
                l = pivot+1;
        }
        return nums[pivot];
    }

    int partition(vector<int> &nums, int l, int r, int pivot) {
        while (l < r) {
            while (nums[l] < nums[pivot]) l++;
            swap(nums[l], nums[pivot]);
            pivot = l;
            while (nums[r] > nums[pivot]) r--;
            swap(nums[r], nums[pivot]);
            pivot = r;
        }
        return pivot;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
