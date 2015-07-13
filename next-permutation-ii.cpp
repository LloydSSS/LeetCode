// http://www.lintcode.com/en/problem/next-permutation-ii/
// 从后往前找第一个非降序的元素，然后再找后面降序序列中刚好比它大的元素，交换两个的位置，对这个降序序列进行逆序

#include "lintcode.h"

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        int len = nums.size();
        if (len <= 1) return;
        int i = len-2;
        while (i >= 0 && nums[i] >= nums[i+1])
            i--;
        if (i >= 0) {
            int j = i;
            while (j+1 < len && nums[j+1] > nums[i])
                j++;
            swap(nums[i], nums[j]);
        }
        int l = i+1, r = len-1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	int a[] = {2,1,1};
	vector<int> v;
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        v.push_back(a[i]);
    }
    vector<int> ans = sol.nextPermutation(v);
    for (int i = 0; i < ans.size(); ++i) {
    	cout << ans[i] << " ";
    }
    cout << endl;
	return 0;
}
