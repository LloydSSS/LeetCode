// http://www.lintcode.com/en/problem/continuous-subarray-sum/
// dp, 纪录开始下标
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
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        vector<int> ans(2);
        if (A.size() == 0)
            return ans;
        vector<int> dp(A.size());
        vector<int> from(A.size());
        dp[0] = A[0];
        int max_sum = dp[0];
        for (int i = 1; i < A.size(); ++i) {
            if (dp[i-1] > 0) {
                dp[i] = dp[i-1]+A[i];
                from[i] = from[i-1];
            } else {
                dp[i] = A[i];
                from[i] = i;
            }
            if (dp[i] > max_sum) {
                max_sum = dp[i];
                ans[0] = from[i];
                ans[1] = i;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
