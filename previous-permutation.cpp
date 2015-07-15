// http://www.lintcode.com/en/problem/previous-permuation/
// 和next同理

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
    	int len = nums.size();
    	if (len <= 1) return nums;
    	int i = len-2;
    	while (i >= 0 && nums[i] <= nums[i+1])
    		i--;
    	if (i >= 0) {
	    	int j = i;
	    	while (j+1 < len && nums[j+1] < nums[i])
	    		j++;
	    	swap(nums[i], nums[j]);
    	}
    	int l = i+1, r = len-1;
    	while (l < r) {
    		swap(nums[l], nums[r]);
    		l++;
    		r--;
    	}
    	return nums;
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
