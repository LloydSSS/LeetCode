// http://www.lintcode.com/en/problem/maximum-subarray-ii/
// Time:O(kn), Space:O(kn)
// global_max[i][j]表示从0到i，j个non-overlapping的子数组的最大和
// local_max[i][j]表示从0到i，j个non-overlapping的子数组，最后一个子数组以i结尾的最大和
// local_max[i][j] = max(global_max[ii][j-1] + sumBetween(ii+1, i)), 其中 0<ii<i
// 这样时间复杂度为O(kn2)，还可以继续优化
// 当我们计算完i，计算i+1时，sumBetween(ii+1, i)变成了sumBetween(ii+1, i+1)，实际上只多了一个数，所以我们可以不每次都计算一次。之前的最大的值，到新的还是原来所组合的最大值，只需要和新加的比一下就可以了，所以这个值我们从最左边向右边扫一遍一直维护是可行的，并且只需要维护一个变量local_max而不是数组。
// http://hehejun.blogspot.com/2015/01/lintcodemaximum-subarray-iii.html
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
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
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        int n = nums.size();
        if (n < k) return 0;
        vector<vector<int> > global_max(n+1, vector<int>(k+1, 0));
        for (int j = 1; j <= k; ++j) {
            int local_max = INT_MIN;
            for (int i = j-1; i < n; ++i) {
                local_max = max(local_max, global_max[i][j-1]) + nums[i];
                if (i == j-1)
                    global_max[i+1][j] = local_max;
                else
                    global_max[i+1][j] = max(global_max[i][j], local_max);
            }
        }
        return global_max[n][k];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
