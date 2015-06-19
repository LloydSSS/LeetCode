#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        return longestIncreasingSubsequenceNlogn(nums);
        if (nums.size() == 0) return 0;
        int ans = 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] <= nums[i] && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1;
            }
            if (dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }

    int longestIncreasingSubsequenceNlogn(vector<int> nums) {
        if (nums.size() == 0) return 0;
        int ans = 1;
        vector<int> minV(nums.size(), 0);
        minV[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= minV[ans-1])
                minV[ans++] = nums[i];
            else {
                int pos = binarySearch(minV, ans, nums[i]);
                minV[pos] = nums[i];
            }
        }
        return ans;
    }

    int binarySearch(vector<int> &array, int n, int target) {
        int l = 0, r = n;
        while (l < r) {
            int m = (l+r) >> 1;
            if (array[m] < target)
                l = m+1;
            else if (array[m] >= target)
                r = m;
        }
        return l;
    }
};





int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v = {9,3,6,2,7};
    cout << sol.longestIncreasingSubsequence(v) << endl;
    return 0;
}
