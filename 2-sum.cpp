// http://www.lintcode.com/en/problem/2-sum/
// https://leetcode.com/problems/two-sum/
// Time: O(n2), Space: O(1)
// Brute force

// Time: O(nlogn), Space: O(n)
// 排序，左右夹逼，需要额外的空间纪录排序前的位置

// Time, Space: O(n)
// We could reduce the runtime complexity of looking up a value to O(1) using a hash map that maps a value to its index.

#include "lc.h"

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(target-nums[i]) != hash.end()) {
                return {hash[target-nums[i]]+1, i+1};
            }
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {1, 3};
    auto ans = sol.twoSum(v, 2);
    for (auto a : ans)
        cout << a << endl;
	return 0;
}
