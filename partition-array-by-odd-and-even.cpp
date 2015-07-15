// http://www.lintcode.com/en/problem/partition-array-by-odd-and-even/
// partation

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int l = 0, r = nums.size()-1;

        while (true) {
            while (l <= r && nums[l]%2 == 1) l++;
            while (r >= l && nums[r]%2 == 0) r--;
            if (l >= r) break;
            swap(nums[l], nums[r]);
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    std::vector<int> v = {1,2,3,4,5,6,7};
    sol.partitionArray(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
	return 0;
}
