// Remove Duplicates from Sorted Array II
// http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-array-ii/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) return nums.size();
        int idx = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[idx-2]) {
                nums[idx++] = nums[i];
            }
        }
        nums.erase(nums.begin()+idx, nums.end());
        return idx;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
