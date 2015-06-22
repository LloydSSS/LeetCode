// 4 Sum
// http://www.lintcode.com/en/problem/4-sum/
// a. 排序，选定两个，左右逼近，注意去重
// b. 排序，使用unordered_map<int, vector<pair<int, int> > >缓存结果, 然后o(n2)遍历，注意下标不能重复，注意去重
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
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int> > retv;
        if (nums.size() < 4) return retv;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums.size(); ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = nums.size()-1;
                int sum = target - nums[i] - nums[j];
                while (left < right) {
                    if (left > j+1 && nums[left] == nums[left-1]) {
                        ++left;
                        continue;
                    }
                    if (right < nums.size()-1 && nums[right] == nums[right+1]) {
                        --right;
                        continue;
                    }
                    if (nums[left] + nums[right] == sum) {
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[left]);
                        vec.push_back(nums[right]);
                        retv.push_back(vec);
                        ++left;
                    } else if (nums[left] + nums[right] < sum) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return retv;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
