// Subarray Sum Closest
// http://www.lintcode.com/en/problem/subarray-sum-closest/
// 使用sums存储0~i之间的和，以及i，然后对sums进行排序，相邻元素的差即是一段区间内的和，非相邻元素的差肯定大于相邻元素，顺序扫描即可
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
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        vector<int> ans(2, 0);
        if (nums.size() == 0) return ans;
        vector<pair<int, int> > sums;
        sums.push_back(make_pair(nums[0], 0));
        for (int i = 1; i < nums.size(); ++i) {
            sums.push_back(make_pair(sums[i-1].first+nums[i], i));
        }
        sort(sums.begin(), sums.end());
        int closest = INT_MAX;
        for (int i = 1; i < sums.size(); ++i) {
            if (sums[i].first - sums[i-1].first < closest) {
                closest = sums[i].first - sums[i-1].first;
                ans[0] = min(sums[i].second,  sums[i-1].second)+1;
                ans[1] = max(sums[i].second,  sums[i-1].second);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
