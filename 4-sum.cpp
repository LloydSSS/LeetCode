// 4 Sum
// http://www.lintcode.com/en/problem/4-sum/
// Time: O(n3), Space: O(1)
// a. 排序，选定两个，左右逼近，注意去重(剪枝)
// Time: O(n2), Space: O(n2)
// b. 排序，使用unordered_map<int, vector<pair<int, int> > >缓存结果, 然后o(n2)遍历，注意下标不能重复，注意去重(Lintcode MLE, LeetCode TLE) 剪枝做的不好

#include "lintcode.h"

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int> > ans;
        int n = nums.size();
        if (n < 4) return ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i+1; j < n; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1, right = n-1;
                int sum = target - nums[i] - nums[j];
                while (left < right) {
                    if (left > j+1 && nums[left] == nums[left-1]) {
                        ++left;
                        continue;
                    }
                    if (right < n-1 && nums[right] == nums[right+1]) {
                        --right;
                        continue;
                    }
                    if (nums[left] + nums[right] == sum) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                    } else if (nums[left] + nums[right] < sum) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int> > ans;
        int n = nums.size();
        if (n < 4) return ans;
        sort(nums.begin(), nums.end());

        unordered_multimap<int, pair<int, int>> cache;

        for (int i = 0; i + 1 < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
        for (auto i = cache.begin(); i != cache.end(); ++i) {
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for (auto j = range.first; j != range.second; ++j) {
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                if (a != c && a != d && b != c && b != d) {
                    vector<int> vec = { nums[a], nums[b], nums[c], nums[d] };
                    sort(vec.begin(), vec.end());
                    ans.push_back(vec);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
