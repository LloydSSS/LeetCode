// http://www.lintcode.com/en/problem/3-sum/
// https://leetcode.com/problems/3sum/
// Time: O(n3), Space: O(1)
// Brute force

// Time: O(n2), Space: O(1)
// 排序，三个指针，固定第一个指针之后，另外两个指针左右夹逼，最后注意去重(lintcode 不知道为什么去重失效，需要先排一下序，或者使用set)
// 同样的代码leetcode TLE, 在遍历过程中剪枝而不是最后去重可以AC

#include "lc.h"

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // 去重
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1, k = n-1;
            while (j < k) {
                // 去重
                if (j > i+1 && nums[j] == nums[j-1]) {
                    j++;
                    continue;
                }
                if (k < n-1 && nums[k] == nums[k+1]) {
                    k--;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    //k = n-1;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        //sort(ans.begin(), ans.end());
        //ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    auto ans = sol.threeSum(v);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
	return 0;
}
